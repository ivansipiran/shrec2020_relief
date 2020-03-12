# SHREC 2020 - Relief

## Software requirements
  * CMake >= 2.8
  * CUDA >= 10.0
  * Python >= 3.6
  * Pytorch >= 1.2
  * MATLAB >= 2015
  
## Procedure
#### 1. MeshLib library

MeshLib is a small library to handle triangle meshes. To build the library, go to folder MeshLib and compile the library with these commands:

```
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

These commands will create the .so files in the build directory.

#### 2. PrepareDataSHREC2020

This program will produce point cloud patches for input OFF files. To compile the program, go to folder PrepareDataSHREC2020. Open the CMakeLists.txt file and edit the MESHLIB_LIBRARY variable to the folder of the MeshLib project. Then, execute the following commands:

```
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

These commands will create the program PrepareDataset which receives an OFF input file and produces a set of point cloud patches. To process the entire dataset, you could use the script.sh bash script provided in the repository. If the input file has name 1.off, the point clouds are stored in files 1_0.xyz, 1_1.xyz, ...

#### 3. Description with PointNet
The folder pointnet contains a modified version of the original repository of [pointnet.pytorch](https://github.com/fxia22/pointnet.pytorch). Go to the folder pointnet and execute 

```
pip3 install -e .
```

to install the packages.

We provide the script utils/compute_feature.py  to compute features for the entire SHREC dataset. To execute the script, write the following command:

```
python3 utils/compute_feature.py --model=utils/cls/cls_model_99.pth --num_points=2500 --folder=<data_folder>
```
where <data_folder> is the directory with all the point clouds generated with PrepareDataset program. The output of the description is a file with descriptor per shape. The extension of the descriptor file is .desc.

#### 4. SQFD Distance
The computation of signatures and the final SQFD distance are implemented in MATLAB. The folder SQFD contains a script to compute the signartures and dissimilatiry matrix for the entire dataset. Inside MATLAB, the script must be executed as follows:

```
> runScriptPatterns(<folder>)
```

where <folder> is the directory with the desc files computed by pointnet. In the script, we can change the R, S, Nm parameters of clustering to get different signatures. The output of this script is a file with a dissimilarity matrix.
