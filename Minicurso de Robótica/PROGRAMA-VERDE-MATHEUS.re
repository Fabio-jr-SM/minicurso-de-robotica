#Criando tarefas FRENTE, DIREITA, ESQUERDA e TRAS

#destrava motor, dps define velocidades para os motores
tarefa Frente com numero velocidade = 100{
	TravarMotor("motorDireita", falso)
	TravarMotor("motorEsquerda", falso)
	Motor("motorDireita", velocidade)
	Motor("motorEsquerda", velocidade)
}


#trava motor direita, dps define velocidade para o motor esquerda
tarefa Direita com numero velocidade = 100{
	TravarMotor("motorDireita", verdadeiro)
	TravarMotor("motorEsquerda", falso)
	Motor("motorEsquerda", velocidade)
}

#trava motor esquerda, dps define velocidade para o motor direita
tarefa Esquerda com numero velocidade = 100{
	TravarMotor("motorDireita", falso)
	TravarMotor("motorEsquerda", verdadeiro)
	Motor("motorDireita", velocidade)
}

#destrava os motores, dps define velocidades negativas para ambos
tarefa Tras com numero velocidade = 100{
	TravarMotor("motorDireita", falso)
	TravarMotor("motorEsquerda", falso)
	Motor("motorDireita", 0-velocidade)
	Motor("motorEsquerda", 0-velocidade)
}

tarefa Parar com numero velocidade = 100{
	TravarMotor("motorDireita", verdadeiro)
	TravarMotor("motorEsquerda", verdadeiro)
	Motor("motorDireita", 0-velocidade)
	Motor("motorEsquerda", 0-velocidade)
}

	numero continua = 1

inicio

	enquanto(continua == 1) farei{
		Esperar(50)	#Importante para evitar a quebra no Simulador

		Frente(250)
	
		Escrever(Cor("sensorDireita"))
		se ((Cor("sensorDireita")=="Branco") e (Cor("sensorEsquerda")=="Branco")) entao {
			Frente(300)
			LigarLuz("led",255,0,255)

		}senao{
			se ((Cor("sensorEsquerda")=="Verde")) entao {
						LigarLuz("led",255,255,0)
						Esquerda(200)
						Esperar(6000)
						Parar(100)

			}senao{
				se ((Cor("sensorDireita")=="Verde")) entao {

					Direita(200)
						Esperar(6000)
						Parar(100)

				}senao{
					se ((Cor("sensorDireita")=="Preto") e (Cor("sensorEsquerda")=="Branco")) entao{
						LigarLuz("led",0,0,255)		
						Direita(300)
				}senao{
					se ((Cor("sensorDireita")=="Branco") e (Cor("sensorEsquerda")=="Preto")) entao{
							LigarLuz("led",255,255,0)
							Esquerda(300)
					}senao{
						se ((Cor("sensorDireita")=="Preto") e (Cor("sensorEsquerda")=="Preto")) entao{
							Frente(300)
							LigarLuz("led",255,0,255)
						}senao{
							se ((Cor("sensorDireita")=="Vermelho") e (Cor("sensorEsquerda")=="Vermelho")) entao{
								enquanto((Cor("sensorDireita")=="Vermelho") e (Cor("sensorEsquerda")=="Vermelho")) farei{
								Esperar(50)
								Frente(300)
								LigarLuz("led",255,0,255)
								}
								Parar()
								continua = 2	

							}
						}
					}
				}
			}
		}
	}
}
fim
