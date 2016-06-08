# Gabor_Feature_Extactor

**C++ Based Gabor Feature Extractor using OpenCV**

This class extractors Gabor features of the input image using Gabor wavelets. The wavelet used is of the form: 

![wavelet_equation](https://cloud.githubusercontent.com/assets/7311045/15891645/4e714ce2-2d7e-11e6-98b0-ca6f339a2971.png)

where, μ and *v* define the orientation and scale of the Gabor filters, z=(x,y), ||.|| denotes the norm operator, and the wave vector k_{\mu, \upsilon} = k_{v}e^{i\varnothing _{\mu}} where 
