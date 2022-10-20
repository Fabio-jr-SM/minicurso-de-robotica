#Criando tarefas FRENTE, DIREITA, ESQUERDA e TRAS

#destrava motor, dps define velocidades para os motores
tarefa Frente com numero velocidade = 100{
	TravarMotor("motorFrenteDir", falso)
	TravarMotor("motorTrasDir", falso)
	TravarMotor("motorFrenteEsq", falso)
	TravarMotor("motorTrasEsq", falso)
	Motor("motorFrenteEsq", velocidade)
	Motor("motorFrenteDir",velocidade)
	Motor("motorTrasEsq",velocidade)
	Motor("motorTrasDir",velocidade)
}


#trava motor direita, dps define velocidade para o motor esquerda
tarefa Direita com numero velocidade = 100{
	TravarMotor("motorFrenteDir", verdadeiro)
	TravarMotor("motorTrasDir", verdadeiro)
	TravarMotor("motorFrenteEsq", falso)
	TravarMotor("motorTrasEsq", falso)
	Motor("motorFrenteEsq", velocidade)
	Motor("motorTrasEsq",velocidade)
}

#trava motor esquerda, dps define velocidade para o motor direita
tarefa Esquerda com numero velocidade = 100{
	TravarMotor("motorFrenteDir", falso)
	TravarMotor("motorTrasDir", falso)
	TravarMotor("motorFrenteEsq", verdadeiro)
	TravarMotor("motorTrasEsq", verdadeiro)
	Motor("motorFrenteDir", velocidade)
	Motor("motorTrasDir",velocidade)
}

#destrava os motores, dps define velocidades negativas para ambos
tarefa Tras com numero velocidade = 100{
	TravarMotor("motorFrenteDir", falso)
	TravarMotor("motorFrenteEsq", falso)
	Motor("motorFrenteDir", 0-velocidade)
	Motor("motorFrenteEsq", 0-velocidade)
}

tarefa Parar com numero velocidade = 100{
	TravarMotor("motorFrenteDir", verdadeiro)
	TravarMotor("motorFrenteEsq", verdadeiro)
	TravarMotor("motorTrasDir", verdadeiro)
	TravarMotor("motorTrasEsq", verdadeiro)
}


inicio


	enquanto(verdadeiro) farei{
		Esperar(1)	#Importante para evitar a quebra no Simulador
		
		se ((Cor("sensorCorDir")=="Preto") e (Cor("sensorCorEsq")=="Preto")) entao {

			Frente(200)
			AbrirConsole()
			Escrever("Ambos sensores Preto")

		} senao se((Cor("sensorCorDir")=="Preto") ou (Cor("sensorCorDirExt")=="Preto")) entao {
			
			Direita(200)
			AbrirConsole()
			Escrever("Sensor da Direita Preto")

		} senao se ((Cor("sensorCorEsq")=="Preto") ou (Cor("sensorCorEsqExt")=="Preto")) entao {
			
			Esquerda(200)
			AbrirConsole()
			Escrever("Sensores da Esquerda Preto")

		} senao se ((Cor("sensorCorDir")=="Vermelho") ou (Cor("sensorCorEsq")=="Vermelho")) entao {

			Esperar(10)
			Parar()
			AbrirConsole()
			Escrever("Alguns dos Sensores Vermelho")

		} senao {		
		
			Frente(200)
			AbrirConsole()
			Escrever("Ambos Sensores Branco")

		}
	}
fim