#include <stdio.h>
#include <cs50.h>

int string_is_alpha(string key);
int verify_arguments(int number_arguments, string argument);
void print_text_cifra(string text, string argv);
int caracterer_alpha_26(string argv);
int repiret(string argv);
char to_upper(char c);
int is_upper_case(char c);
int is_lower_case(char c);
int position_letter(char c);
char to_lower(char c);
int is_alpha_char(char c);

int main(int argc, string argv[])
{
    /*
    Funçao principal que controla o programa.
    Tem como objetivo criptografar uma mensagem.
    */

   // Verifica os argumentos da linha de comando.
   if (verify_arguments(argc, argv[1]) != 0)
    {
        return 1;
    }

    // Pede para o usuário inserir o texte que vai ser cifrado
    string text = get_string("Digite seu texto: ");

    printf("Texto cifrado (cirptografia média): ");

    // Imprime na tela o texto cifrado.
    print_text_cifra(text, argv[1]);
}

int verify_arguments(int number_arguments, string argument)
/*
Avaliando os argumentos inseridos na linha de comando.
*/
{
    if (number_arguments != 2) // Se tiver mais de 2 argumentos ou menos de 2 argumentos...
    {
        printf("Insira apenas 1 argumento na linha-de-comando!\n");
        printf("%i\n", number_arguments);
        return 2;
    }
    if (caracterer_alpha_26(argument) != 26) // Se o segundo argumento menos de 26 ou mais de 26 caracteres...
    {
        printf("A chave deve conter 26 caracteres!\n");
        return 3;
    }
    if (string_is_alpha(argument) == 0) // Se os caracteres forem diferentes de um alfabético...
    {
        printf("Insira argumentos alfabéticos!\n");
        return 4;
    }
    if (repiret(argument) == 1) // Se algum caracterer se repetir...
    {
        printf("Nao repita nenhum caractere!\n");
        return 5;
    }
    return 0;
}

int string_is_alpha(string key)
/*
Confere se todos os caracteres avaliados
da string da linha de comandosao alfabéticas.
*/
{
    int n = 0;
    int c = 0;
    while (key[n] != '\0')
    {
        if (is_alpha_char(key[n]) == 0)
        {
            c++;
        }
        n++;
    }
    if (c == n)
    {
        return 1;
    }
    return 0;
}

int caracterer_alpha_26(string argv)
/*
Retorna o número de caracteres que tem na  string
*/
{
    int n = 0;
    while (argv[n] != '\0')
    {
        n++;
    }
    return n;
}

int repiret(string argv)
/*
Caso algum caracterer na string se repita retorna 1, senao retorna 0
*/
{
    for (int i = 0; i <= 26; i++)
    {
        int n = 0;
        for (int j = 0; j <= 26; j++)
        {
            if (to_upper(argv[i]) == to_upper(argv[j]))
            {
                n++;
            }
        }
        if (n > 1)
        {
            return 1;
        }
    }
    return 0;
}

void print_text_cifra(string text, string argv)
/*
Função responsável por imprimir o texto
cifrado (criptografado) na tela.
*/
{
     int n = 0;
    while (text[n] != '\0')
    {
        char cifra;
        char c = text[n];
        int position;

        if (is_alpha_char(c) == 0)
        {
            position = position_letter(c);
            if (is_lower_case(c) == 0)
            {
                cifra = to_lower(argv[position]);
            }
            else
            {
                cifra = to_upper(argv[position]);
            }
        }
        else
        {
            cifra = c;
        }
        printf("%c", cifra);
        n++;
    }
    printf("\n");
}

int is_lower_case(char c)
/*
Retorna 0 se o caracterer avaliado for lower case, senão retorna 1
*/
{
    if (c >= 'a' && c <= 'z')
    {
        return 0;
    }
    return 1;
}

int is_upper_case(char c)
/*
Retorna 0 se o caracterer avaliado for upper case, senão retorna 1
*/
{
    if (c >= 'A' && c <= 'Z')
    {
        return 0;
    }
    return 1;
}

int position_letter(char c)
/*
Retorna a posição da letra alfabética para ser usada na
matriz. Ex: a = 0, A = 0, b = 1, B = 1..., Z = 26, z = 26.
*/
{
    if (is_upper_case(c) == 0)
    {
        return (int) c - 65;
    }
    else if (is_lower_case(c) == 0)
    {
        return (int) c - 97;
    }
    return (int) c;
}

char to_upper(char c)
/*
Converte um caracterer lower em um upper
*/
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 32;
    }
    return c;
}

char to_lower(char c)
/*
Converte um caracterer upper em um lower
*/
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 32;
    }
    return c;
}

int is_alpha_char(char c)
/*
Retorna verdadeiro se o caracterer avaliado for alfabético
*/
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 0;
    }
    return 1;
}

/*
ERROS DETECTADOS

Número do erro retornado:
- Descrição do erro...

N 1:
- O primeiro erro gerado é problema com o programa, ou seja, o programador que desenvolveu este código errou em algum detalhe, por favor, notifique-o em seu github, Karlos-Vinicius.

N 2:
- O erro de número 1 ocorre quando o usuário insere mais de um argumento na linha-de-comando. Para que não aconteça mais, insira somente a quantidade de argumentos necessários, como: ./substitution qwertyu... Evite algo como: ./substitution q w e r t y u... Por mais que você insira 26 letras, serão 27 argumentos diferentes, sendo que o primeiro argumento é ./substitution

N 3:
- O erro de número 2 é gerado quando é inserido mais de 26 caracteres ou menos de 26 caracteres , para resolve-lo, é necessário que seja inserido no total 26 letras(caracteres) no segundo argumento, sendo que no primeiro é ./substitution. Para evitar isso, insira o segundo argumento com 26 caracteres alfabéticos, como: .substitution qwertyuioplkjhgfdsazxcvbnm.

N 4:
- Este erro de número 3 é gerado quando os caracteres inseridos for(em) diferente(s) de um caractere alfabético, ou seja, tudo que for diferente de a, b, c, d... W, X, Y, Z, como 1, 2, 3 *, ^, á, é, ê, â... Para que não ocorra novamente, insira somente 26 caracteres alfabéticos, como /substitution qwertyuioplkjhgfdsazxcvbnm. Tudo bem se você mistura caracteres em maiúscula ou minúscula, ou somente um dos dois.

N 5:
- Este erro de número 4 é gerado quando é inserido caracteres alfabéticos repetidos, como ./substitution aabbccee... Para evitá-lo, é necessário que não seja inserido nenhum caractere repetido, pois precisamos de um total de 26 caracteres, o mesmo número do alfabeto usado no português, inglês... Exemplo, da entrada: ./substitution azqxswcdevfrbgtnhymjukilop.
*/