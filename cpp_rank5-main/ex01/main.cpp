#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "=== TEST 1: Criacao valida ===" << std::endl;
    try
    {
        Bureaucrat b1("Bira", 50);
        Form f1("Contrato", 60, 30);

        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Criacao invalida ===" << std::endl;
    try
    {
        Bureaucrat b2("Erro", 200); // inválido
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form f2("ErroForm", 0, 10); // inválido
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Assinatura com sucesso ===" << std::endl;
    try
    {
        Bureaucrat b3("Boss", 10);
        Form f3("Importante", 20, 10);

        b3.signForm(f3);

        std::cout << f3 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Assinatura falha ===" << std::endl;
    try
    {
        Bureaucrat b4("Estagiario", 100);
        Form f4("TopSecret", 20, 10);

        b4.signForm(f4);

        std::cout << f4 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}