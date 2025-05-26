#ifndef RESERVA_H
#define RESERVA_H

#include "structs.h"
#include <stdio.h>

extern Reserva reservas[];
extern int totalReservas;

void cadastrarReserva();
void listarReservas();
Reserva* buscarReservaPorId(int id);
void editarReserva(int id);
void removerReserva(int id);
void salvarReservas();
void carregarReservas();

#endif
