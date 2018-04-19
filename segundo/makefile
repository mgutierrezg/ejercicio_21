grafica_no_lineal.pdf: datos.txt graficas_ad2.py
	python graficas_ad2.py
datos.txt: nolin 
	./nolin > datos.txt
nolin: ad_nolin.cpp
	c++ ad_nolin.cpp -o nolin
