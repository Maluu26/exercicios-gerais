#include<stdio.h>
#include"empresa.h"

tEmpresa criaEmpresa(int id){
    tEmpresa empresa;
    empresa.id  = id;
    return empresa;
}
tEmpresa leEmpresa(){
    tEmpresa empresa;
    
    int num_funcionario, id;
    scanf("%d %d", &id, &num_funcionario);
    tFuncionario funcionario;
    empresa = criaEmpresa(id);
    empresa.qtdFuncionarios = 0;
    for(int i = 0; i<num_funcionario;i++){
        funcionario = leFuncionario();
        empresa = contrataFuncionarioEmpresa(empresa, funcionario);

    }
    return empresa;
}
/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    int quant_certa= 0;
    for(int i=0;i<empresa.qtdFuncionarios+1;i++){
        if(getIdFuncionario(empresa.funcionarios[i])==funcionario.id){
            printf("A empresa %d ja possui um funcionario com o id %d", empresa.id, getIdFuncionario(funcionario));
            return empresa;
        }
    }
  
            empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
            empresa.qtdFuncionarios++;
            return empresa;
    
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa){
    printf("Empresa %d:\n", empresa.id);
}
