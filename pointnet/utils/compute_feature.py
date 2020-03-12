from __future__ import print_function
import argparse
import torch
import torch.nn.parallel
import torch.utils.data
from torch.autograd import Variable
from pointnet.dataset import ShapeNetDataset
from pointnet.model import PointNetCls
import torch.nn.functional as F
import numpy as np
import time


parser = argparse.ArgumentParser()

parser.add_argument('--model', type=str, default = '',  help='model path')
parser.add_argument('--num_points', type=int, default=2500, help='input batch size')
parser.add_argument('--folder', type=str, default='', help='folder with input files')

opt = parser.parse_args()
print(opt)

#Creamos un clasificador PointNet, pero solo para extraer features
classifier = PointNetCls(k=16, only_feature=True, feature_transform=True)
classifier.cuda()

#Cargamos un modelo pre-entrenado
classifier.load_state_dict(torch.load(opt.model))
classifier.eval()

#Son 200 modelos
for model in range(1, 201):
    desc = []
    start_time = time.time()

    #Cada modelo tiene 200 parches
    for patch in range(200):
        #Leemos la nube de puntos
        filepath = opt.folder + '/' + str(model) + '_' + str(patch) + '.xyz'
        point_set = np.loadtxt(filepath).astype(np.float32)

        #Seleccionamos 2500 aleatorios
        choice = np.random.choice(3000, opt.num_points, replace=False)
        point_set = point_set[choice, :]

        #Normalizamos la data a media cero y desviacion 1
        point_set = point_set - np.expand_dims(np.mean(point_set, axis=0), 0)
        dist = np.max(np.sqrt(np.sum(point_set**2, axis=1)), 0)
        point_set = point_set / dist

        #Creamos tensor y lo mandamos al GPU
        point_set = torch.from_numpy(point_set)
        point_set = point_set.unsqueeze(0)
        point_set = point_set.transpose(2, 1)
        point_set = point_set.cuda()

        #Computamos el feature
        feature, _,_ = classifier(point_set)

        feature = feature.cpu().detach().numpy()
        desc.append(feature)

    desc = np.vstack(desc)
    print(desc.shape)

    #Guardamos los descriptores
    outputfile = opt.folder + '/' + str(model) + '.desc'
    np.savetxt(outputfile, desc, fmt='%2.6f')

    print('Model {} processed in {} seconds'.format(model, time.time()-start_time))
