#!/bin/bash

#Set the data folder
DATA_DIR=/data/Relief
POINTNET_DIR=/home/isipiran/Software/pointnet.pytorch
SQFD_DIR=/home/isipiran/Software/SQFD

numPatches=200
configDir='Config'$numPatches

# Go to the data directory
cd $DATA_DIR
mkdir $configDir

#Compute the patches and point clouds (in the same folder)
for i in $(ls *.off);
do
	echo $i
	PrepareDataset $i $numPatches 0.05
done

#Move point clouds to the corresponfing config folder
mv *.xyz $configDir

#Describe the point clouds with POINTNET
cd $POINTNET_DIR
python3 utils/compute_feature.py --model=utils/cls/cls_model_99.pth --num_points=2500 --folder=$DATA_DIR/$configDir --num_samples=$numPatches

#Compute the signatures and the SQFD
cd $SQFD_DIR
matlab -nodesktop -r "runScriptPattern('"$DATA_DIR/$configDir"')"

