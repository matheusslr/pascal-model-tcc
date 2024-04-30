INPUTS="320 240,640 480,800 600,1024 768,1280 1024,1920 1080,3840 2140,7680 4320"

pascalanalyzer ./raytrace -c 1:20 -i "${INPUTS}" -r 10 -o model_output -m 100 100
