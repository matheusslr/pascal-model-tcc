INPUTS="100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500"

pascalanalyzer ./example -c 1:20 -i "${INPUTS}" -r 10 -o model_output -m 1000 300
