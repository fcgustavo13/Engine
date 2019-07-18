

#include "pch.h"
#include <iostream>
//#include "GameFramework/Actor.h"
//#include "PlantillaDeClase.generated.h"

int main()
{
    std::cout << "Hello World!\n"; 
}


class PelotaTiroOblicuo
{
private:
	float RunningTime;
	FVector	posicion;
	FVector velocidad;
	float GRAVEDAD;
	float rebotes;
	float calcularCantidadDeRebotes(float altura);
	void moverPelota();
	float MIN_ALTURA_REBOTE;
	float COEF_DE_REBOTE;
public:
	
	PelotaTiroOblicuo();
	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};

PelotaTiroOblicuo::PelotaTiroOblicuo() {
	posicion = GetActorLocation();
	rebotes = calcularCantidadDeRebotes(posicion.Z);
	GRAVEDAD = -9.8f;
	MIN_ALTURA_REBOTE = 0.5f;
	COEF_DE_ALTURA_DE_REBOTE = 0.5F;
	COEF_DE_VELOCIDAD_DE_REBOTE = 0.5F;
}
//pre : 
//post : 
void PelotaTiroOblicuo::moverPelota() {
	float velocidadAltura = velocidad.Y;
	float tiempoEntreRebotes = 0;
	if (rebotes >= 0) {
		posicion.X += velocidad.X * RunningTime;// alterar RunningTime no siempre el evento es al inicio
		posicion.Y += velicidad.Y * RunningTime;
		posicion.Z += velocidadAltura * RunningTime + 0.5 * GRAVEDAD *
			(RunningTime - tiempoEntreRebotes) * (RunningTime - tiempoEntreRebotes);

		if (posicion.Z < 0.1f) {
			rebotes--;
			tiempoEntreRebotes = RunningTime;
			if( velocidadAltura > 0)// soluciona el caso de velocidad Y negativa para rebote, ver casteo
				velocidadAltura = velocidadAltura * COEF_DE_VELOCIDAD_DE_REBOTE;
			else{
				velocidadAltura = -velocidadAltura * COEF_DE_VELOCIDAD_DE_REBOTE;
		}
	}
}
//pre: altura > 0 // cambiar posteriormente por la posicion del suelo.
//post: si la altura es menor o igual a MIN_ALTURA_REBOTE no rebotara el objeto
float PelotaTiroOblicuo::calcularCantidadDeRebotes(float altura) {
	float rebotes = 0;
	float nuevaAltura = altura;
	while (nuevaAltura > MIN_ALTURA_REBOTE) {
		rebotes++;
		nuevaAltura = nuevaAltura * COEF_DE_REBOTE;
	}

	return rebotes;
}




