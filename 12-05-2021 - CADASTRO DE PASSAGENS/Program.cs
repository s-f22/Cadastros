using System;

namespace _12_05_2021___CADASTRO_DE_PASSAGENS
{
    class Program
    {
        static void Main(string[] args)
        {

            int senha = 123456;
            int senhaErrada = 0;
            int opcao, i, k;
            bool start;
            bool programa = false;
            int qtdeDados = 4;
            int qtdePassageiros = 5;
            string[,] passageiros = new string[qtdePassageiros, qtdeDados]; //{ {"Mac","Jan"}, {"Mimi","Jeff"} };
            int quantosDados = 0;
            int contagemDeCadastros = 0;

            Console.WriteLine("Bem vindo ao SENAI Air Lines!\n");
            Console.WriteLine("Para acessar o sistema, informe abaixo sua senha com 6 numeros:");

            do
            {
                Console.Write("Senha: ");

                int userSenha = int.Parse(Console.ReadLine());

                if (userSenha == senha)
                {
                    Console.WriteLine("\nAcesso liberado.\n");
                    start = true;
                }
                else
                {
                    Console.Write("Senha inválida. Tente novamente.\n");
                    start = false;
                    senhaErrada++;
                }

                if (senhaErrada == 3)
                {
                    Console.Write("Senha incorreta digitada 3 vezes. Acesso bloqueado.");
                    break;
                }

            } while (start == false);

            do
            {
                Console.WriteLine("Selecione a opção desejada conforme menu abaixo:\n");
                Console.WriteLine("1-Cadastrar até 5 passagens; \n2-Listar passagens cadastradas; \n0-Sair\n");
                opcao = int.Parse(Console.ReadLine());

                switch (opcao)
                {
                    case 1:

                        for (i = contagemDeCadastros; i < qtdePassageiros; i++)
                        {

                            Console.Write($"\nDigite o nome do passageiro: ");
                            passageiros[i, quantosDados] = Console.ReadLine().ToUpper();

                            quantosDados++;

                            Console.Write($"Insira a origem da viagem: ");
                            passageiros[i, quantosDados] = Console.ReadLine().ToUpper();

                            quantosDados++;

                            Console.Write($"Insira o destino final: ");
                            passageiros[i, quantosDados] = Console.ReadLine().ToUpper();

                            quantosDados++;

                            Console.Write($"Insira a data do voo (dd/mm/aaaa): ");
                            passageiros[i, quantosDados] = Console.ReadLine().ToUpper();

                            quantosDados = 0;


                            Console.WriteLine($"\nCadastro efetivado com sucesso!\n");

                            contagemDeCadastros++;

                            Console.WriteLine($"Deseja continuar com um novo cadastro? (1-sim; 2-não)\n");
                            int continua = int.Parse(Console.ReadLine());
                            if (continua != 1)
                            {
                                programa = false;
                                break;
                            }
                            else if (i == passageiros.Length - 1)
                            {
                                programa = true;

                            }

                        }
                        Console.WriteLine($"Cadastros finalizados.\n");

                        break;

                    case 2:
                        if (contagemDeCadastros == 0)
                        {
                            Console.WriteLine($"\nVocê ainda não possui passagens cadastradas.\n");
                        }
                        else
                        {
                            Console.WriteLine($"Informações cadastradas:\n");

                            for (k = 0; k < contagemDeCadastros; k++)
                            {

                                Console.WriteLine($"\nNome do passageiro: {passageiros[k, quantosDados]}");
                                quantosDados++;

                                Console.WriteLine($"Origem da viagem: {passageiros[k, quantosDados]}");
                                quantosDados++;

                                Console.WriteLine($"Destino da viagem: {passageiros[k, quantosDados]}");
                                quantosDados++;

                                Console.WriteLine($"Data da viagem: {passageiros[k, quantosDados]}\n");

                                quantosDados = 0;

                            }
                        }
                        break;

                    case 0:
                        Console.WriteLine($"Sistema Encerrado.");
                        programa = true;
                        break;

                    default:
                        Console.WriteLine($"Opção inválida. Tente novamente.");
                        programa = false;
                        break;
                }


            } while (programa == false);

            Console.WriteLine($"\nO Senai Air Lines agradece sua visita.");

        }
    }
}
