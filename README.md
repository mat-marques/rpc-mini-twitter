# rpc-mini-twitter
Trabalho de Sistema Operacionais Utilizando os Conceitos de RPC

Descri��o do Trabalho:

Considere um servi�o semelhante ao Twitter, onde usu�rios podem postar pequenos textos (posts) em um determinado t�pico de interesse. 
Sua tarefa ser� implementar esse servi�o utilizando RPCe threads. As caracter�sticas do servi�o do sistema ser�o apresentadas abaixo.

O sistema de micro blogue apresenta dois elementos (ou tiers), projetados e implementados separadamente:

 - Elementos Cliente: respons�veis por receber os posts e encaminhar ao servidor, n�o � necess�rio uma interface gr�fica;

 - Elemento Servidor: respons�vel pelo armazenamento dos posts em uma base de dados e atender as solicita��es dos clientes.

A base de dados deve armazenar: instante atual (timestamp), ID do usu�rio da postagem, ID do post (ou hashtag), texto (post). 
O ID do usu�rio da postagem estar� no formato @username, representando um usu�rio. O ID do post apresenta o formato #t�pico. 
O texto (post) � de conte�do livre, com no m�ximo 80 caracteres.

As opera��es permitidas no micro twitter:

 - Usu�rios enviam post em um determinado t�pico: post_topic(@username, #t�pico, texto) esse texto deve ser enviado a todos os usu�rios que o seguem.

 - Usu�rio torna-se seguidor de outro usu�rio: follow (@username, @username to follow)

 - Listar usu�rios cadastrados no micro twitter: list_users()

 - Cadastrar usu�rio no micro twitter: create_user(@username) � cadastra o usu�rio como participante do twitter

 - Buscar t�pico: usu�rio solicita lista de t�picos (ou hashtags) cadastrados;

 - Criar um novo t�pico: usu�rio envia uma solicita��o de cria��o de novo t�pico: new_topic(@username,#topic)

 - Usu�rio deixa de seguir e de receber posts de um determinado usu�rio: unfollow (@username, @username <que ser� desligado>)

 - O usu�rio recupera todos os posts, apenas do t�pico identificado desde a data especificada at� a data atual: retrievetopic(@username, #t�pico, timestamp)

 - Usu�rio envia um post (Twittar): twitte(@username,text), esse texto deve ser enviado a todos os usu�rios que o seguem.

 - A arquitetura do micro twitter apresenta um elementos servidor e v�rios elementos clientes. O servidor deve apresentar multhreads.



Executar os seguintes testes:

 - Teste de Desempenho: fa�a a proposta de um teste de desempenho para o sistema implementado, apresentado os resultados obtidos com os testes.



Elementos para entrega do trabalho:

 - relat�rio contendo: resultado da execu��o dos testes, como utilizar o sistema e descreva poss�veis melhorias que poderiam ser implementadas na pr�xima vers�o, 
   indicando como integrar essas altera��es em seu c�digo;

 - c�digo fonte do programa: com coment�rios internos ao c�digo;