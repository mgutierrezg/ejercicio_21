grafica.pdf: datos.txt graficas_ad.py
	python graficas_ad.py
datos.txt: lineal 
	./lineal > datos.txt
lineal: ad_lineal.cpp
	c++ ad_lineal.cpp -o lineal
