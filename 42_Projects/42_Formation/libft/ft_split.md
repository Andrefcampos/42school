
<li>O objetivo da função split é dividir uma string em subtsrings com base em um caractere delimitador e é por conta disso que ela recebe dois parâmetros: um para a string mãe e outro que é o caractere delimitador. Observe o código que eu escrevi e depois vamos destrinchá-lo passo a passo:</li>
<pre><code>
static int ft_cntstr(char const *s, char c)
{
	int cnt;
	int i;

	cnt = 0;
	i = 0;
	if (!*s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cnt++;
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
	}
	return (cnt);
}

char **ft_split(char const *s, char c)
{
	char **str_list;
	size_t str_len;
	int i;
	int i_list;

	i = 0;
	i_list = 0;
	str_list = (char **) malloc((ft_cntstr(s, c) + 1) * sizeof(char *));
	if ((!s) || (!str_list))
		return (NULL);
	while (s[i] != '\0')
	{
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
		if (s[i] != '\0')
		{
			str_len = 0;
			while ((s[i + str_len] != c) && (s[i + str_len] != '\0'))
				str_len++;
			str_list[i_list++] = ft_substr(s, i, str_len);
				i = i + str_len;
		}
	}
	str_list[i_list] = NULL;
	return (str_list);
}
</code></pre>

<li>Como você pode perceber, o nosso arquivo da split teve que utilizar duas funções para rodar, uma vez que se eu tentasse desenvolver toda a lógica dentro da mesma função, acabaria ultrapassando as 25 linhas da função, o que a norminette não me permite fazer. Por conta disso fiz uma função que vai servir para contar a quantidade de substrings que existem dentro da string principal. Vamos começar a nossa análise por essa função:</li>

<h3 style="color: #00FFFF">Protótipo:</h3>

<li><code>static int ft_cntstr(char const *s, char c)</code>: podemos perceber que essa função tem um retorno estático do tipo inteiro. O estático serve para dizer que essa função só vai funcionar dentro deste arquivo. Já o tipo inteiro vai servir para dizer que essa função precisa retornar um tipo inteiro. Isso é feito porque vamos contar o número de substrings que exitem dentro de nossa string principal.</li>
<ul>
<li>Podemos perceber que essa função recebe dois parâmetros:</li>
</ul>
<ol>
	<li><code>char const *s</code>: Essa é a string mãe, a string que vamos receber para achar as substrings que estão dentro dentro dela. Perceba que ela é do tipo const, ou seja, não pode ter seu valor alterado durante a execução do código.</li>
	<li><code>char c</code>: Esse parâmetro representa o caractere delimitador, que vai ser utilizado para fazer a separação de uma palavra para a outra.</li>
</ol>
<h3 style="color: #00FFFF">Variáveis:</h3>
<li><code>int cnt;</code>: Essa variável vai ser inicializado com zero e é ela quem vai contar a quantidade de substrings dentro da string mãe.</li>
<li><code>int i;</code>: Essa é variável que vamos utilizar para percorrer todos os índices da string principal, que contém as substrings dentro.</li>

<h3 style="color: #00FFFF">Lógica:</h3>
<li>Depois de inicializarmos nossas variáveis a primeira coisa que fazemos é verificar se nossa string existe, ou seja, se o ponteiro não aponta direto para um caractere nulo (<code>'\0'</code>) que delimita o fim de uma string. Se for esse o caso e a string não existir retornamos zero porque significa que se não existe string não vai existir, também, nenhuma sub-string para contar. Observe:</li>
<pre><code>
if (!*s)
	return (0);
</code></pre>

<li>Depois disso entramos no nosso primeiro loop while que continua a rodar a string-mãe até encontrar o caractere nulo que delimita o fim de uma string.</li>
<li>Dentro desse loop colocamos um outro loop que vai verificar se ele encontrou o caractere delimitador (<code>char c</code>). Caso ele encontre o delimitador, iteramos o nosso i para ir para o próximo caractere.</li>
<li>Depois disso verificamos se ainda não chegamos ao delimitador final da string. Se esse for o caso iteramos nosso contador (<code>cnt</code>)para dizer que uma palavra foi achada.</li>
<li>Depois disso entramos em outro while que vai verificar se a posição atual da string é diferente do caractere e se também não é o fim da string. Caso isso seja um fato, iteramos nosso índice para seguir em frente até encontramos um caractere delimitador ou acharmos o fim dessa string.</li>
<li>Depois disso retornamos o nosso <code>cnt</code> que vai contar o inteiro que representa a quantidade de substrings que foram encontradas.</li>
<li>Agora que entendemos como a função <code>ft_cntstr</code> vamos voltar nossa atenção para split e ver como ela funciona exatamente:</li>
  
  <h3 style="color: #00FFFF">Protótipo:</h3>
  - <code>char **ft_split (char const *s, char c)</code>: Como podemos observar a função split retorna um ponteiro que aponta para uma lista de strings que são, justamente, nossas substrings. Observe que a função possuí dois parâmetros:
	  - <code>char const s*</code>: Esse parâmetro é a nossa string-mãe. Por isso que ela deve ter um const em seu tipo também, uma vez que ela não vai poder mudar seu valor durante a execução do programa.
	  - <code>char c</code>: Esse parâmetro é o nosso caractere delimitador, ele que é responsável por fazer a separação de cada sub-string.

  <h3 style="color: #00FFFF">Variáveis:</h3>
  - Logo que começamos nossa função declaramos 4 variáveis:
	  - <code>char **str_list</code>: Essa variável é um ponteiro que aponta para uma lista de strings, que vai ser a lista das nossas sub-strings.
	  - <code>size_t str_len</code>: Essa variável vai servir para guardamos o comprimento de cada sub-string. Essa informação é essencial para que possamos percorrer a string-mãe corretamente e fazer a passagem necessária por cada caractere, ou conjunto de caracteres, que formos encontrando ao longo do caminho.
	  - <code>int i;</code>: Essa variável vai ser o index de toda a string-mãe. Ele é quem vai ser utilizado para percorrer cada caractere da string "completa".
	  - <code>int i_list</code>: Já essa variável vai ser o index da nossa lista de sub-strings, ou seja, ele é quem vai apontar para o início de cada uma de nossas sub-strings.

  <h3 style="color: #00FFFF">Atribuições:</h3>
<ul>
<li>Depois de declarar as variáveis o próximo passo é fazer as atribuições a essas variáveis:</li>
</ul>
<ol>
	<li><code>i = 0;</code>: Inicializamos o index da string-mãe com zero para garantir que vamos começar a percorrer essa string desde o seu primeiro caractere.</li>
	<li><code>i_list = 0;</code>: Inicializamos o index de nossa lista, também com zero, mas para garantir que comecemos a apontar para cada sub-string a partir da primeira sub-string.</li>
	<li><code>str_list = (char **) malloc((ft_cntstr(s, c) + 1) * sizeof(char *));</code>: Nessa atribuição estamos reservando um espaço na memória utilizando a função <code>ft_cntstr</code> para saber exatamente o tamanho da string em questão. Somamos o 1 para garantir a inclusão do caractere nulo no final da string. Depois multiplicamos esse tamanho pelo <code>sizeof</code> para garantir que estamos alocando espaço suficiente na memória para armazenar todas as substrings que vão estar na nossa lista (<code>str_list</code>).</li>
</ol>
  <h3 style="color: #00FFFF">Lógica:</h3>
<li>Depois de inicializarmos essas três variáveis começamos nossa lógica fazendo uma primeira verificação para saber se a nossa string-mãe ou a nossa lista de substrings não existem. Ou seja se nossa alocação de memória deu certo. Se qualquer uma das duas não existirem retornamos nulo. Observe:</li>
<pre><code>
if ((!s) || (!str_list))
	return (NULL);
</code></pre>
<li>Depois continuamos nossa lógica entrando em nosso loop while que continua rodando até achar o caractere nulo, que determina o final da string. Dentro desse loop entramos em um outro while que continua rodando até encontrarmos o caractere delimitador e o final da string.</li>
<li>Depois disso entramos em uma condicional que vai verificar se chegamos no caractere nulo que determina o final da string-mãe. Dentro dessa condicional atribuímos zero ao comprimento de nossa string para garantir que ela comece a contar os caracteres a partir da primeira ocorrência. Observe:</li>
  
<pre><code>
while (s[i] != '\0')
{
	while ((s[i] == c) && (s[i] != '\0'))
		i++;
	if (s[i] != '\0')
	{
		str_len = 0;
		while ((s[i + str_len] != c) && (s[i + str_len] != '\0'))
			str_len++;
		str_list[i_list++] = ft_substr(s, i, str_len);
		i = i + str_len;
	}
}
</code></pre>
<ul>
<li>Agora vamos entender o que acontece dentro desse if, depois de inicializarmos o comprimento da string com zero.</li>
<li>Logo na sequência, dentro da condicional, iniciamos um loop que vai rodar enquanto nossa string na posição atual mais o comprimento total string seja diferente do caractere delimitador e do caractere nulo que representa o fim da sub-string. Se essas condições forem atendidas sabemos que ainda não terminamos uma sub-string e nossa <code>str_len</code> vai ser incrementada.</li> 
<li>Quando essa condição deixar de ser satisfeita, significa que encontramos o final da sub-string e que o valor de <code>str_len</code> está indicando corretamente o tamanho da sub-string que precisamos extrair. Nesse ponto, utilizamos a função <code>ft_substr</code> para criar uma nova sub-string a partir da posição atual <code>i</code> e com comprimento <code>str_len</code>. Essa sub-string recém-criada é atribuída à posição <code>i_list</code> na nossa lista <code>str_list</code> de sub-strings. Após isso, incrementamos <code>i</code> com <code>str_len</code> para apontar para o próximo caractere após a sub-string que acabamos de extrair. - Continuamos a varrer a string principal até que tenhamos encontrado todas as sub-strings possíveis. Ao final desse loop, apontamos o último elemento da lista <code>str_list</code> como nulo, para indicar o término da lista. - Finalmente, retornamos nossa lista <code>str_list</code>, que contém todas as sub-strings extraídas da string principal com base no caractere delimitador.</li>
</ul>