# GS_Edge
Componentes : 
Gustavo Carmo Santana Sousa Lima / RM 98279
Pedro Henrique Silva de Morais / RM98804
Lucas Rodrigues Delfino/ RM550196
Luisa Cristina dos Santos Neves/ RM551889
Gabriel aparecido Cassalho Xavier / RM99794


Projeto Equipe :
Nosso projeto se baseia em uma Rede social com o objetivo de divulgar ongs que distribuem comida , 
a rede fará uma ponte com doares , tanto pessoas comuns ou empresas que tem interesse em realizar 
doações de comida e dinheiro buscando ajudar as instituições que necessitam. Nossa plataforma terá três usuários
as ONG's que poderão postar eventos , ações sociais e metas , os doares , que passarão por esses posts procurando
instuições com seu perfil para uma possível doação e pessoas carentes que também navegaram nos eventos das ONG's
e poderão participar buscando seu alimento.

Protótipo Arduino :
Nosso protótipo no arduino consiste em um sistema de segurança e controle de temperatura para um freezer , onde
receberemos os alimentos dos doadores , para abrir a porta do freezer que está sendo simulada pelo servomotor deverá
acertar a senha pelo monitor Serial(Obs: a leitura do serial é por caracteres então digite uma caractere por vez)
se o usuário digitar a senha incorreta mais de três vezes será acionado o buzzer e o led vermelho como forma de alerta
de invasores , se a senha estiver correta os componentes delsigarão e o sensor de temperatura começará a funcionar
(Obs : O ideal seria ter dois lcds , um para senha outro para o sensor , porém como nos limitamos a apenas um arduino
tivemos que improvisar funcionando apenas uma verificação por vez para o lcd ficar mais limpo), como se trata de um freezer
a verificação de temperatura é bem baixa, abaixo de -12°C está no ideal ,acima disso está fora do ideal,
quando a temperatura estiver fora do ideial será acionado o buzzer e o led vermelho como forma de alerta , se a temperatura estiver ideal
apenas o led verde acenderá(Usei um while para que a temperatura verificada seja apenas num delay de 2.5 segundos 
para que o valor verificado não seja instantâneo evitando errros), para sair do freezer e fechá-lo você deverá acionar o botão
que desliga todos o componentes e fecha a porta(simulada pelo servomotor) , com isso terá que realizar o acesso novamente 
com senha e voltará o loop do código.

