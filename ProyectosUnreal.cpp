

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
}

void PelotaTiroOblicuo::moverPelota() {
	float velocidadAltura = velocidad.Y;
	if (rebotes >= 0) {
		posicion.X += velocidad.X * RunningTime;// alterar RunningTime no siempre el evento es al inicio
		posicion.Y += velicidad.Y * RunningTime;
		posicion.Z += velocidadAltura * RunningTime + 0.5 * GRAVEDAD + RunningTime * RunningTime;
		if (posicion.Z < 0.1f) {
			rebotes--;
			velocidadAltura = velocidadAltura * 0.5f;
		}
	}
}
//pre: altura > 0 // cambiar posteriormente por la posicion del suelo.
float PelotaTiroOblicuo::calcularCantidadDeRebotes(float altura) {
	float rebotes = 0;
	float nuevaAltura = altura;
	while (nuevaAltura > 0.5) {
		rebotes++;
		nuevaAltura = nuevaAltura * 0.5f;
	}

	return rebotes;
}



