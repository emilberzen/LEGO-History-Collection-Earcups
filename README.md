# Margarine 

©(year) YOKE ApS. All rights reserved.

## Description

This is a realtime Stable diffusion project that displays the visitors as margarine. Exhibited at Medicinsk museion.

## Hardware 
-Fembolt camera
-Computer

## Requirements

-Cuda 12.1 
-GIT

### Installation 

To get this up and running you need to follow some steps, but it's pretty straight forward. 
In the StreamDiffusionTD component in Touchdesigner there is a 'install' section.
You need GIT in path and you need CUDA 12.1 for this to work.

First you set the base folder. 
Then you press:
Download / update SD > Install SD (venv + all req) > Install TensorRT.

To get the Model ID/Path to work locally, you need to manually download a huggingface repo/model in the diffusers format and then link the repo folder. example 'F:/StreamDiffusion/models/Model/sd-turbo' is what I have the parameter set as. and I ran this cmd 'git clone https://huggingface.co/stabilityai/sd-turbo' in the models\Model folder inside StreamDiffusion base folder.

Then you should be able to get it to run :) 
