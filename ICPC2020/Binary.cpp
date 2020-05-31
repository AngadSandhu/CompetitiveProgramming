#include <iostream>
using namespace std;
int dinero, precio_hambur;
bool f(int cant_hambur){
	return dinero >= cant_hambur*precio_hambur;
}
int main() {
	vector<int> v(n);
	int valor;
	int pos1 = lower_bound(v.begin(),v.end(),valor) - v.begin(); // Primera posicion tq sea mayor o igual a valor
	int pos2 = upper_bound(v.begin(),v.end(),valor) - v.begin(); // Primera posicion tq sea mayor a valor
	// O(Costof(x) * log2(n))
	// 3/2 -> 1.5 ->
	// Down -> 1
	// Up -> 2
	                                    12
	// FFFFFFVVVVVV                     FV
	     L ...    R                     L
	                                    Rm
	// FFFFFFVVVVVV                                    
	// Ultimo falso
	int l = 0, r = N, med;
	while(l < r){
		med = l + (r-l+1)/2; // Up
		if(f(med) == true) r = med-1;
		else l = med;
	}
	Respuesta es (l);
	// VVVVVVFFFFFF                         VF
	// Ultimo verdadero                     L
	int l = 0, r = N, med;                  Rm
	while(l < r){
		med = l + (r-l+1)/2; // Up
		if(f(med) == true) l = med;
		else r = med-1;
	}
	// FFFFFFVVVVVV                          FV
	//Primer verdadero                        R
	int l = 0, r = N, med;                   mL
	while(l < r){
		med = l + (r-l)/2; // Down
		if(f(med) == true) r = med;
		else l = med+1;
	}
	// VVVVVVFFFFFFF                         VF
	//Primer falso                            R
	int l = 0, r = N, med;                   mL
	while(l < r){
		med = l + (r-l)/2; // Down
		if(f(med) == true) l = med+1;
		else r = med;
	}
	//Decimales
	//Error menor a 10^-6
	double eps = 1e-6;
	double l = 0, r = N, med;                   
	while(r-l > eps){
		med = (r+l)/2;
		if(f(med) == true) l = med;
		else r = med;
	}
	l en decimales aproximada con un error menor a eps
	
	return 0;
}