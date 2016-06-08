# Gabor_Feature_Extactor

**C++ Based Gabor Feature Extractor using OpenCV**

This class extractors Gabor features of the input image using Gabor wavelets. The wavelet used is of the form: 

![wavelet_equation](https://cloud.githubusercontent.com/assets/7311045/15891645/4e714ce2-2d7e-11e6-98b0-ca6f339a2971.png)

where, μ and *v* define the orientation and scale of the Gabor filters, z=(x,y), ||.|| denotes the norm operator, and the wave vector ![wavelet_equation2](https://cloud.githubusercontent.com/assets/7311045/15892003/f44d6014-2d7f-11e6-8e6f-1bfc20f15b6b.png) where ![wavelet_equation3](https://cloud.githubusercontent.com/assets/7311045/15892074/79417706-2d80-11e6-9171-5483db04f35b.png) and ![wavelet_equation4](https://cloud.githubusercontent.com/assets/7311045/15892079/7cc48940-2d80-11e6-9e2c-45e4bcb609e5.png) is the spacing factor between filters in the frequency domain. 
