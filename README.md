# bug_itkimageio
bug minimal example for problems reading a 3D tiff image using itkimageio component

From discourse discussion:
https://discourse.itk.org/t/find-all-available-modules-from-groupio/351/11

```
cmake -DUSEITKIMAGEIO:BOOL=ON -DITK_DIR=~/Software/ITK/build ../src
```

versus, the hard-coded io components

```
cmake -DUSEITKIMAGEIO:BOOL=OFF -DITK_DIR=~/Software/ITK/build ../src
```

The later works, the former reads a 64x64x16 image as a 64x64x1

Run the test with the included 3d tiff image fixture using:

```
ctest -V
```

