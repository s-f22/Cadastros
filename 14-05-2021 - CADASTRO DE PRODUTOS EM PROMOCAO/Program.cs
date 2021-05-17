using System;

namespace _14_05_2021___CADASTRO_DE_PRODUTOS_EM_PROMOCAO
{
    class Program
    {
        static string op_1;
        static bool start_1 = false;
        static string op_2;
        static string op_3;
        static bool start_2 = false;
        static int qtdeInicial = 2;
        static int qtdeExtra = 0;
        static int totalDeProdutos = qtdeInicial + qtdeExtra;
        static int contadorDeProdutos = 0;
        static string op_4;
        static bool start_4 = false;

        static string[] nomes = new string[totalDeProdutos];
        static float[] precos = new float[totalDeProdutos];
        static bool[] promocao = new bool[totalDeProdutos];
        static string promo;


        public static void Main(string[] args)
        {

            Console.WriteLine("Bem vindo ao Cadastro de Produtos!\n");

            do
            {
                Console.WriteLine("Insira a opção desejada: \n\n1-Mostrar Menu; \n2-Sair\n");
                op_1 = Console.ReadLine().ToLower();

                if (op_1 == "1")
                {
                    start_1 = true;
                }
                else if (op_1 == "2")
                {
                    Console.WriteLine("Sistema encerrado com sucesso.");
                    break;
                }
                else
                {
                    Console.WriteLine("Opção inválida. Tente novamente.\n");
                    start_1 = false;
                }

            } while (start_1 == false);

            ChamarMenu();   //VERIFICAR CHAMAR FUNÇÃO "MOSTRAR MENU" AQUI, OU DENTRO DO IF ACIMA, CASO 1
            Console.WriteLine("\nSistema encerrado com sucesso. Agradecemos sua visita\n");
        }

        //----------------------------------------------------------------------------------------------------------------------------------------

        public static void ChamarMenu()
        {

            Console.WriteLine("\nMENU GERAL.");

            do
            {
                Console.WriteLine("Insira a opção desejada: \n\n1-Cadastrar produto; \n2-Listar produto(s)\n3-Aumentar lista de produtos\n4-Finalizar sistema");
                op_2 = Console.ReadLine().ToLower();

                switch (op_2)
                {
                    case "1":
                        //Console.WriteLine("Teste chama funcao Cadastrar.");
                        CadastrarProduto();     //CHAMAR FUNÇÃO "CADASTRAR PRODUTO" AQUI

                        do
                        {
                            Console.WriteLine("Deseja continuar no sistema? (s/n)");
                            op_3 = Console.ReadLine().ToLower();

                            if (op_3 == "s")
                            {
                                start_2 = false;
                            }
                            else if (op_3 == "n")
                            {
                                start_2 = true;
                            }
                            else
                            {
                                Console.WriteLine("Opção inválida. Tente novamente.\n");
                            }

                        } while (op_3 != "s" && op_3 != "n");

                        break;

                    case "2":

                        if (contadorDeProdutos == 0)
                        {
                            Console.WriteLine("\nVoce ainda não possui pdrodutos cadastrados.\n");
                        }
                        else
                        {
                            ListarProduto();    //CHAMAR FUNÇÃO "LISTAR PRODUTO" AQUI
                        }

                        do
                        {
                            Console.WriteLine("Deseja continuar no sistema? (s/n)");
                            op_3 = Console.ReadLine().ToLower();

                            if (op_3 == "s")
                            {
                                start_2 = false;
                            }
                            else if (op_3 == "n")
                            {
                                start_2 = true;
                            }
                            else
                            {
                                Console.WriteLine("Opção inválida. Tente novamente.\n");
                            }

                        } while (op_3 != "s" && op_3 != "n");

                        break;

                    case "3":

                        AumentarLista();     //CHAMAR FUNÇÃO "AUMENTAR LISTA" AQUI

                        do
                        {
                            Console.WriteLine("Deseja continuar no sistema? (s/n)");
                            op_3 = Console.ReadLine().ToLower();

                            if (op_3 == "s")
                            {
                                start_2 = false;
                            }
                            else if (op_3 == "n")
                            {
                                start_2 = true;
                            }
                            else
                            {
                                Console.WriteLine("Opção inválida. Tente novamente.\n");
                            }

                        } while (op_3 != "s" && op_3 != "n");

                        break;

                    case "4":
                        Console.WriteLine("\nSistema encerrado com sucesso.");
                        start_2 = true;
                        break;

                    default:
                        Console.WriteLine("Opção inválida. Tente novamente.\n");
                        start_2 = false;
                        break;
                }

            } while (start_2 == false);

        }

        //----------------------------------------------------------------------------------------------------------------------------------------

        public static void CadastrarProduto()
        {
            Console.WriteLine("\nCADASTRO DE PRODUTOS.\n");

            //Console.WriteLine($"A quantidade total agora é de {totalDeProdutos} produtos.");
            //Console.WriteLine($"O contador esta em {contadorDeProdutos} produtos.");

            do
            {

                if (contadorDeProdutos == totalDeProdutos)
                {
                    Console.WriteLine("Limite de cadastros atingido.");
                    Console.WriteLine("Solicite um aumento de cadastros.\n");
                    break;
                }

                Console.Write("Insira o nome do produto: ");
                nomes[contadorDeProdutos] = Console.ReadLine().ToUpper();

                Console.Write("Insira o preço do produto: R$");
                precos[contadorDeProdutos] = float.Parse(Console.ReadLine());

                Console.Write("Este produto está em promoção: (s/n)");
                promo = Console.ReadLine().ToLower();

                if (promo == "s")
                {
                    promocao[contadorDeProdutos] = true;
                }
                else if (promo == "n")
                {
                    promocao[contadorDeProdutos] = false;
                }
                else
                {
                    Console.WriteLine("Opção inválida. Tente novamente.\n");
                }

                contadorDeProdutos++;

                Console.WriteLine("Produto cadastrado com sucesso.");

                do
                {
                    Console.WriteLine("\nDeseja continuar cadastrando produtos? (s/n)");
                    op_4 = Console.ReadLine().ToLower();

                    if (op_4 == "s")
                    {
                        start_4 = true;
                    }
                    else if (op_4 == "n")
                    {
                        start_4 = false;
                        break;
                    }
                    else
                    {
                        Console.WriteLine("Opção inválida. Tente novamente.\n");
                        start_4 = false;
                    }

                } while (start_4 == false);


            } while (contadorDeProdutos <= totalDeProdutos && start_4 == true);


        }

        //----------------------------------------------------------------------------------------------------------------------------------------

        public static void ListarProduto()
        {
            Console.WriteLine("\nLISTAR PRODUTOS.\n");

            for (var i = 0; i < contadorDeProdutos; i++)
            {
                Console.WriteLine($"Nome do produto: {nomes[i]}");
                Console.WriteLine($"Preço do produto: R${precos[i]}");
                Console.WriteLine($"Produto em promoção: {promocao[i]}\n");
            }
        }

        //----------------------------------------------------------------------------------------------------------------------------------------

        public static void AumentarLista()
        {
            Console.WriteLine("\nAUMENTAR LISTA DE PRODUTOS.\n");

            Console.WriteLine("Quantos itens deseja incluir na lista?");
            qtdeExtra = int.Parse(Console.ReadLine());

            totalDeProdutos = qtdeInicial + qtdeExtra;

            //Console.WriteLine($"A quantidade total agora é de {totalDeProdutos} produtos.");
            //Console.WriteLine($"O contador esta em {contadorDeProdutos} produtos.");

            Console.WriteLine("\nLista atualizada. Realize seus cadastros no menu principal.\n");

            Array.Resize(ref nomes, totalDeProdutos);
            Array.Resize(ref precos, totalDeProdutos);
            Array.Resize(ref promocao, totalDeProdutos);

        }

        //----------------------------------------------------------------------------------------------------------------------------------------

    }
}
