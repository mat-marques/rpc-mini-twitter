# rpc-mini-twitter
Trabalho de Sistema Operacionais Utilizando os Conceitos de RPC

Descrição do Trabalho:

Considere um serviço semelhante ao Twitter, onde usuários podem postar pequenos textos (posts) em um determinado tópico de interesse. 
Sua tarefa será implementar esse serviço utilizando RPCe threads. As características do serviço do sistema serão apresentadas abaixo.

O sistema de micro blogue apresenta dois elementos (ou tiers), projetados e implementados separadamente:

 - Elementos Cliente: responsáveis por receber os posts e encaminhar ao servidor, não é necessário uma interface gráfica;

 - Elemento Servidor: responsável pelo armazenamento dos posts em uma base de dados e atender as solicitações dos clientes.

A base de dados deve armazenar: instante atual (timestamp), ID do usuário da postagem, ID do post (ou hashtag), texto (post). 
O ID do usuário da postagem estará no formato @username, representando um usuário. O ID do post apresenta o formato #tópico. 
O texto (post) é de conteúdo livre, com no máximo 80 caracteres.

As operações permitidas no micro twitter:

 - Usuários enviam post em um determinado tópico: post_topic(@username, #tópico, texto) esse texto deve ser enviado a todos os usuários que o seguem.

 - Usuário torna-se seguidor de outro usuário: follow (@username, @username to follow)

 - Listar usuários cadastrados no micro twitter: list_users()

 - Cadastrar usuário no micro twitter: create_user(@username) – cadastra o usuário como participante do twitter

 - Buscar tópico: usuário solicita lista de tópicos (ou hashtags) cadastrados;

 - Criar um novo tópico: usuário envia uma solicitação de criação de novo tópico: new_topic(@username,#topic)

 - Usuário deixa de seguir e de receber posts de um determinado usuário: unfollow (@username, @username <que será desligado>)

 - O usuário recupera todos os posts, apenas do tópico identificado desde a data especificada até a data atual: retrievetopic(@username, #tópico, timestamp)

 - Usuário envia um post (Twittar): twitte(@username,text), esse texto deve ser enviado a todos os usuários que o seguem.

 - A arquitetura do micro twitter apresenta um elementos servidor e vários elementos clientes. O servidor deve apresentar multhreads.



Executar os seguintes testes:

 - Teste de Desempenho: faça a proposta de um teste de desempenho para o sistema implementado, apresentado os resultados obtidos com os testes.



Elementos para entrega do trabalho:

 - relatório contendo: resultado da execução dos testes, como utilizar o sistema e descreva possíveis melhorias que poderiam ser implementadas na próxima versão, 
   indicando como integrar essas alterações em seu código;

 - código fonte do programa: com comentários internos ao código;