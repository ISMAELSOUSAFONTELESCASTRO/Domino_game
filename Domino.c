
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void compra(int mao[21][2], int mesa[28][2],int contador, int banco){
  if(banco != 0){
      mao[contador][0] = mesa[banco-1][0];
      mao[contador][1] = mesa[banco-1][1];
      mesa[banco-1][0] = 0;
      mesa[banco-1][1] = 0;
  }
}

int Pjogada(int matriz1[21][2],int matriz2[21][2],int mesa[55][2] ,int rodada){
//Essa função dita qual dos dois jogadores irá começar
  int i, j,indicador1 = 0,indicador2 = 0,soma1=0,soma2=0,maior1[1][2]={{0,0}} ,maior2[1][2],maiorT[1][2];

  if(rodada == 1){
    for(i = 0;i < 7; i++){
      for(j = 0; j < 1; j++){
        //esse loop aqui irá percorrer as mãos dos dois jogadores para verificar as três condições, ou seja, se existe ou não um carrilhão, em caso negativo, qual a peça de maior soma e nos raros casos de empate, irá verificar qual peça possui o maior número
        if(matriz1[i][j] == matriz1[i][j+1]){
          if((maior1[0][0] = 0) && (maior1[0][1]=0) ){
            maior1[0][0] = matriz1[i][j];
            maior1[0][1] = matriz1[i][j+1];
            indicador1 = 1;
          }
          if(matriz1[i][j] > maior1[0][0]){
          maior1[0][0] = matriz1[i][j];
          maior1[0][1] = matriz1[i][j+1];
          indicador1 = 1;
          }
        }

        else if(indicador1 != 1){
          if(soma1 == 0){
            soma1 = (matriz1[i][j])+(matriz1[i][j+1]);
            maior1[0][0] = matriz1[i][j];
            maior1[0][1] = matriz1[i][j+1];
          }

          else{
            if((matriz1[i][j])+(matriz1[i][j+1]) > soma1){
              soma1 = (matriz1[i][j])+(matriz1[i][j+1]);
              maior1[0][0] = matriz1[i][j];
              maior1[0][1] = matriz1[i][j+1];
            }
          }
        }

        if(matriz2[i][j] == matriz2[i][j+1]){
          if((maior2[0][0] = 0) && (maior2[0][1]=0)){
            maior2[0][0] = matriz2[i][j];
            maior2[0][1] = matriz2[i][j+1];
            indicador2 = 1;
          }
          if(matriz2[i][j] > maior2[0][0]){
            maior2[0][0] = matriz2[i][j];
            maior2[0][1] = matriz2[i][j+1];
            indicador2 = 1;
          }
        }

        else if(indicador2 != 1){
          if(soma2 == 0){
            soma2 = (matriz2[i][j])+(matriz2[i][j+1]);
            maior2[0][0] = matriz2[i][j];
            maior2[0][1] = matriz2[i][j+1];
          }

          else{
            if((matriz2[i][j])+(matriz2[i][j+1]) > soma2){
              soma2 = (matriz2[i][j])+(matriz2[i][j+1]);
              maior2[0][0] = matriz2[i][j];
              maior2[0][1] = matriz2[i][j+1];
            }
          }
        }
      }
    }

  //Essa parte verifica as condições antes citadas
    if((indicador1 = 1) && (indicador2 = 0)){
      mesa[27][0] = maior1[0][0];
      mesa[27][1] = maior1[0][1];
      printf("O Jogador 1 começa, a peça [%d/%d] foi jogada parar você.\n",mesa[27][0],mesa[27][1]);
      for(i = 0;i < 7;i++){
        for(j=0;j<1;j++){
          if((maior1[0][0] == matriz1[i][j])&&(maior1[0][1] == matriz1[i][j+1])){
            for(i=i;i<7;i++){
              for(j=0;j<1;j++){
              matriz1[i][j] = matriz1[i+1][j];
              matriz1[i][j+1] = matriz1[i+1][j+1];
              }
            }
          }
        }
      }
      return 1 ;
    }

    else if((indicador1 = 0) && (indicador2 = 1)){
      mesa[27][0] = maior2[0][0];
      mesa[27][1] = maior2[0][1];
      printf("O Jogador 2 começa, a peça [%d/%d] foi jogada para você.\n",mesa[27][0],mesa[27][1]);
      indicador2 = 2;
      for(i = 0;i < 7;i++){
        for(j=0;j<1;j++){
          if((maior2[0][0] == matriz2[i][j])&&(maior2[0][1] == matriz2[i][j+1])){
            for(i=i;i<7;i++){
              for(j=0;j<1;j++){
              matriz2[i][j] = matriz2[i+1][j];
              matriz2[i][j+1] = matriz2[i+1][j+1];
              }
            }
          }
        }
      }
      return 2;
    }

    else if((indicador1 = 1) && (indicador2 = 1)){
      if(maior1[0][0] > maior2[0][0]){
        mesa[27][0] = maior1[0][0];
        mesa[27][1] = maior1[0][1];
        printf("\nO jogador 1 começa, a peça [%d/%d] foi jogada para você.\n",mesa[27][0],mesa[27][1]);
        for(i = 0;i < 7;i++){
          for(j=0;j<1;j++){
            if((maior1[0][0] == matriz1[i][j])&&(maior1[0][1] == matriz1[i][j+1])){
              for(i=i;i<7;i++){
                for(j=0;j<1;j++){
                matriz1[i][j] = matriz1[i+1][j];
                matriz1[i][j+1] = matriz1[i+1][j+1];
                }
              }
            }
          }
        }
        return 1;
      }

      else if(maior1[0][0] < maior2[0][0]){
        mesa[27][0] = maior2[0][0];
        mesa[27][1] = maior2[0][1];
        printf("\nO jogador 2 começa, a peça [%d/%d] foi jogada para você.\n",mesa[27][0],mesa[27][1]);
        indicador2 = 2;
        for(i = 0;i < 7;i++){
          for(j=0;j<1;j++){
            if((maior2[0][0] == matriz2[i][j])&&(maior2[0][1] == matriz2[i][j+1])){
              for(i=i;i<7;i++){
                for(j=0;j<1;j++){
                matriz2[i][j] = matriz2[i+1][j];
                matriz2[i][j+1] = matriz2[i+1][j+1];
                }
              }
            }
          }
        }
        return 2;
      }
    }

    else if((indicador1 = 0) && (indicador2 = 0)){

      if(soma1 > soma2){
        mesa[27][0] = maior1[0][0];
        mesa[27][1] = maior1[0][1];
        printf("O jogador 1 começa, a peça [%d/%d] foi jogada para você.\n",mesa[27][0],mesa[27][1]);
        for(i = 0;i < 7;i++){
          for(j=0;j<1;j++){
            if((maior1[0][0] == matriz1[i][j])&&(maior1[0][1] == matriz1[i][j+1])){
              for(i=i;i<7;i++){
                for(j=0;j<1;j++){
                matriz1[i][j] = matriz1[i+1][j];
                matriz1[i][j+1] = matriz1[i+1][j+1];
                }
              }
            }
          }
        }
        return 1;
      }

      else if(soma1 < soma2){
        mesa[27][0] = maior2[0][0];
        mesa[27][1] = maior2[0][1];
        printf("O jogador 2 começa, a peça [%d/%d] foi jogada para você.\n",mesa[27][0],mesa[27][1]);
        indicador2 = 2;
        for(i = 0;i < 7;i++){
          for(j=0;j<1;j++){
            if((maior2[0][0] == matriz2[i][j])&&(maior2[0][1] == matriz2[i][j+1])){
              for(i=i;i<7;i++){
                for(j=0;j<1;j++){
                  matriz2[i][j] = matriz2[i+1][j];
                  matriz2[i][j+1] = matriz2[i+1][j+1];
                }
              }
            }
          }
        }
        return 2;
      }

      else if(soma1 == soma2){
        if(maior1[0][0] > maior2[0][0]){
          mesa[27][0] = maior1[0][0];
          mesa[27][1] = maior1[0][1];
          printf("O jogador 1 começa, a peça [%d/%d] foi jogada para você.\n",mesa[27][0],mesa[27][1]);
          for(i = 0;i < 7;i++){
            for(j=0;j<1;j++){
              if((maior1[0][0] == matriz1[i][j])&&(maior1[0][1] == matriz1[i][j+1])){
                for(i=i;i<7;i++){
                  for(j=0;j<1;j++){
                  matriz1[i][j] = matriz1[i+1][j];
                  matriz1[i][j+1] = matriz1[i+1][j+1];
                  }
                }
              }
            }
          }
          return 1;
        }

        else if(maior1[0][0] < maior2[0][0]){
          mesa[27][0] = maior2[0][0];
          mesa[27][1] = maior2[0][1];
          printf("O jogador 2 começa, a peça [%d/%d] foi jogada para você.\n",mesa[27][0],mesa[27][1]);
          indicador2 = 2;
          for(i = 0;i < 7;i++){
            for(j=0;j<1;j++){
              if((maior2[0][0] == matriz2[i][j])&&(maior2[0][1] == matriz2[i][j+1])){
                for(i=i;i<7;i++){
                  for(j=0;j<1;j++){
                  matriz2[i][j] = matriz2[i+1][j];
                  matriz2[i][j+1] = matriz2[i+1][j+1];
                  }
                }
              }
            }
          }
          return 2;
      }
    }
  }
}
  rodada = 2;
  return 0;
}
int remover(int ladoe, int ladod, int matriz[21][2], int contador )
{
    int i;
    for (i = 0; i < contador; i++)
    {
        if((ladoe == matriz[i][0] && ladod == matriz[i][1])||(ladod == matriz[i][0] && ladoe == matriz[i][1]))
        {
            while(i < contador){
            matriz[i][0] = matriz[i + 1][0];
            matriz[i][1] = matriz[i + 1][1];
            i++;
            }
            return 1;
        }
    }
}

int lerInteiro() {
    int entrada_usuario;
    int leitura_correta = 0;

    do {

        // Tenta ler um número inteiro da entrada do usuário
        if (scanf("%d", &entrada_usuario) == 1) {
            // A entrada é um número inteiro válido
            leitura_correta = 1;
        } else {
            // A entrada não é um número inteiro válido
            printf("Por favor, digite um número inteiro válido.\n");

            // Limpa o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
        }
    } while (!leitura_correta);

    return entrada_usuario;
}
int peca_valida(int mao[21][2], int tabuleiro[55][2],int numpecas, int e, int d) {
    int i = 0, j = 0, k = 0 , aux = 0, result = 0;
    int vetor [numpecas][2];
        for (i = 0; i < numpecas; i++) {
            if (mao[i][1] == tabuleiro[e][0] || mao[i][0] == tabuleiro[d][1] || mao[i][0] == tabuleiro[e][0] || mao[i][1] == tabuleiro[d][1]) {
              vetor[j][0] =  mao[i][0];
              vetor[j][1] =  mao[i][1];
              j++;
              result = 1;
            }
        }
        if(result == 1){
          printf("\nPEÇAS VALIDAS: \n");
        for (i = 0; i < j; i++)
        {

              printf("[%d | %d]", vetor[i][0], vetor[i][1]);
            }
        }
        printf("\n");
        return result;
}

int JOGO(int matriz[55][2],int mao[21][2], int e, int d)
{
  int peca_jogada[2];
  int decisao;
  int i;
  int temp;

  int tem = 0;
  /*REGRAS DO DOMINÓ
  1-Dado que o jogador inicial já foi escolhido, e a peça inicial já foi posta, temos que:
  se o jogador tiver uma peça valida:
  */
  while(tem == 0)
  {
    do
    {
      printf("\nselecione o lado da mesa que deseja jogar( 0 para esquerdo, 1 para direito, 2 para sair)\n");
      decisao = lerInteiro();
      if(decisao == 2)
      {
        return 2;
      }
      printf("\nselecione a peça da sua mão que deseja jogar \n");
     peca_jogada[0]= lerInteiro();
     peca_jogada[1] = lerInteiro();
      if(decisao == 0)
      {
        for(i = 0; i < 21; i++)
        {
          if((peca_jogada[0] == mao[i][0] && peca_jogada[1] == mao[i][1]) || (peca_jogada[0] == mao[i][1] && peca_jogada[1] == mao[i][0]))
          {
            //usa-se função peça valida(modificada) para conferir se a peça aqui pode ser jogada.

            if (peca_jogada[0] == matriz[e][0] ||  peca_jogada[1] == matriz[e][0])
            {
              tem = 1;
              //usa-se função que irá reorganizar peça jogada, se necessário
              if(peca_jogada[1] != matriz[e][0])
              {
                temp = peca_jogada[0];
                peca_jogada[0] = peca_jogada[1];
                peca_jogada[1] = temp;
              }
              matriz[e-1][0] = peca_jogada[0];
              matriz[e-1][1] = peca_jogada[1];
              return 0;
            }
          }
        }
      }
      else if(decisao == 1)
      {
        for(i = 0; i < 21; i++)
        {
          if(peca_jogada[0] == mao[i][0] && peca_jogada[1] == mao[i][1] || peca_jogada[0] == mao[i][1] && peca_jogada[1] == mao[i][0])
          {
            //usa-se função peça valida(modificada) para conferir se a peça aqui pode ser jogada.
            if (peca_jogada[0] == matriz[d][1] ||  peca_jogada[1] == matriz[d][1])
            {
              tem = 1;
              //usa-se função que irá reorganizar peça jogada, se necessário
              if(peca_jogada[0] != matriz[d][1])
              {
                temp = peca_jogada[0];
                peca_jogada[0] = peca_jogada[1];
                peca_jogada[1] = temp;
              }
              matriz[d+1][0] = peca_jogada[0];
              matriz[d+1][1] = peca_jogada[1];
              return 1;
            }
          }
        }
    }
    else
    {
      printf("\nEscolha uma opção valida.\n");
    }
    }
    while(decisao > 1);
    if (tem == 0)
    {
      printf("\npeça inexistente em sua mão, tente novamente. \n");
    }

  }
}
int main(){
    int choice,loop = 1,loopint = 1, contador1 = 7, contador2 = 7, vez1 = 0, vez2 = 0, rodada = 1, movimento = 0;
    int pecas_no_banco = 14;
    FILE *file;
  while(loop == 1){
    printf("Bem vindo à Super Dominó's Online 3d Multiplayer.apk!\n\n");
    printf("Menu inicial\n\n1-Nova partida\n2-Carregar partida\n3-Regras do Super Dominó's Online 3d Multiplayer.apk!\n4-Sair para a tela inicial\n");
    choice = lerInteiro();

    if(choice == 1){

      srand(time(NULL));
      int mesa[28][2]={{0,0},{0,1},{1,1},{2,0},{2,1},{2,2},{3,0},{3,1},{3,2},{3,3},{4,0},{4,1},{4,2},{4,3},{4,4},{5,0},{5,1},{5,2},{5,3},{5,4},{5,5},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{6,6}};
      int mao1[21][2],mao2[21][2],linha[55][2],i=0,j,a,linhas[14],aux, e=27, d=27, n;
      do{
        linhas[i] = rand()%28;
        int igual = 0;
        for(a=0;a<i;a++){
            if(linhas[a] == linhas[i]){
                igual = 1;
            }
        }
        if(igual == 0){
            i++;
        }
      }while(i<14);
      //parte do código que escolhe aleatorio ^
      //printf("mao 1: \n");
      for(i=0;i<7;i++){
        a = linhas[i];
        //printf("[%d]",linhas[i]); teste pra ver se os indices correspondiam
        for(j=0;j<2;j++){
            mao1[i][0] = mesa[a][0];
            mao1[i][1] = mesa[a][1];
        }
        //printf(" ");
      }
    //parte do codigo que distribui as pecas pro primeiro jogador ^
      for(i=7;i<14;i++){
        a = linhas[i];
        //printf("|");
        //printf("[%d]",linhas[i]); teste pra ver se os indices correspondiam
        for(j=0;j<2;j++){
            mao2[i-7][0] = mesa[a][0];
            mao2[i-7][1] = mesa[a][1];
            //printf("%d|",mao2[i-7][j]);
        }
        //printf(" ");
      }
    //parte do codigo que distribui as pecas pro segundo jogador ^
      for(i=1;i<14;i++){
        for(j=0;j<i;j++){
            if(linhas[i]>linhas[j]){
                aux = linhas[i];
                linhas[i] = linhas[j];
                linhas[j] = aux;
            }
        }
      }
    /*for(i=0;i<14;i++){
        printf("%d ",linhas[i]);
    }
    printf("\n"); teste pra ver se o vetor imprimia em ordem decrescente*/
    //parte do codigo que ordena o vetor em ordem decrescente ^, por que senao ele muda a posicao dos indices e erra
      for(i=0;i<14;i++){
        for(a=0;a<28;a++){
            if(linhas[i] == a){
                do{
                    mesa[a][0] = mesa[a+1][0];
                    mesa[a][1] = mesa[a+1][1];
                    a++;
                }while(a<28);
            }
        }
      }
    //parte do codigo que 'apaga' os valores ja utilizados do vetor ^
      //printf("\npecas na mesa: \n");
      //for(i=0;i<14;i++){
        //printf("|");
        //for(j=0;j<2;j++){
            //printf("%d|",mesa[i][j]);
        //}
       // printf("  ");
     //}
    //printa as pecas da mesa ^
      if(Pjogada(mao1, mao2, linha, rodada) == 1){
        contador1 = 6;
        vez1 = 2;
        vez2 = 1;
        //printf("\n%d\n",contador1);
      }

      else{
        contador2 = 6;
        vez1 = 1;
        vez2 = 2;
        //printf("\n%d\n",contador2);
      }

     while(loop == 1) {
       if(vez1 == rodada){
         vez1 = vez1 + 2;
         while(loopint == 1){
          if(contador1 == 0){
            printf("\n\n!!!!!JOGADOR 1 VENCEU!!!!!\n\n");
            exit(0);
          }
          else{
          printf("\nRODADA %d\n", rodada + 1);

          printf("\nTurno do jogador 1\n");
          system("read -p \"PRESSIONE ENTER PARA CONTINUAR\" continue ");
          printf("\n\nSua mão:\n\n");
           for(i=0; i <contador1;i++){
             printf("[%d/%d]",mao1[i][0],mao1[i][1]);
           }
           printf("\nTABULEIRO:\n\n");
           for(i = e; i < d + 1; i++)
           {
             printf(" [ %d|%d ]" , linha[i][0], linha[i][1]);
           }
          printf("\nEscolha seu movimento\n1-Jogar\n2-Comprar uma peça\n3-Passar sua vez\n4-Salvar e sair\n");
          movimento = lerInteiro();

          if(movimento == 1){



            if(peca_valida(mao1,linha,contador1,e,d) == 1){
            //Função do Xamuel

            n = JOGO(linha, mao1, e, d);
            if(n == 0)
             {
               remover(linha[e-1][0], linha[e-1][1],mao1, contador1);
               contador1 --;
               if(contador1 == 0){
                 printf("Jogador 1 venceu");
                 exit(0);
               }
               e--;
              rodada ++;
              break;
             }
             else if(n == 1)
             {
               remover(linha[d + 1][0], linha[d + 1][1],mao1, contador1);
                contador1 --;
               d++;
              rodada ++;
              break;
             }
            else if(n == 2)
             {
              continue;
             }
            }
            else{
              printf("JOGADA INVALIDA, COMPRE UMA PEÇA!\n");
            }
          }

          if(movimento == 2){
            if(pecas_no_banco == 0){
              printf("Sem peças disponíveis, jogue ou passe a vez.\n");
            }
            else{
                if(peca_valida(mao1,linha,contador1,e,d) == 1)
                {
                  printf("PEÇAS DISPONIVEIS NA MÃO");
                }
                else
                {
                compra(mao1, mesa, contador1, pecas_no_banco);
                pecas_no_banco --;
                contador1++;
                }
            }
          }

          if(movimento == 3){
            if(peca_valida(mao1,linha,contador1,e,d) != 1 && pecas_no_banco == 0)
            {
             printf("Você passou sua vez!");
             rodada++;
             break;
            }else{
              printf("JOGUE UMA PEÇA OU COMPRE DA MESA");
            }
          }
          if(movimento == 4){
            int escolha;
            printf("\nTem certeza que deseja Salvar e Sair?\n1-Sim\n2-Não\n");
            escolha = lerInteiro();
            if(escolha == 1){
              file = fopen("DOMINO.txt", "w");
              if(file){
                fprintf(file, "%d\n%d\n", contador1, contador2);
                for(int i = 0; i < contador1; i++){
                    fprintf(file, "%d %d ", mao1[i][0], mao1[i][1]);
                }
                fprintf(file, "\n");
                for(int i = 0; i < contador2; i++){
                    fprintf(file, "%d %d ", mao2[i][0], mao2[i][1]);
                }
                fprintf(file, "\n%d\n%d\n%d\n%d\n%d\n", vez1, vez2, rodada, e, d);
                for(i = e; i < d + 1; i++)
           {
             fprintf(file, "%d %d " , linha[i][0], linha[i][1]);
           }
                fprintf(file,"\n");
                for(i = 0; i < 14; i++){
                   fprintf(file, "%d ", linhas[i]);
                 }
                fclose(file);
                return 0;
              }
              break;
            }
          }
          }
        }
       }
        if(vez2 == rodada){
          vez2 = vez2 + 2;
          while(loopint == 1){
            if(contador2 == 0){
              printf("\n\n!!!!!JOGADOR 2 VENCEU!!!!!\n\n");
              exit(0);
            }
            else{
           printf("\nRODADA %d\n", rodada + 1);
           printf("\nTurno do jogador 2\n");
            system("read -p \"PRESSIONE ENTER PARA CONTINUAR\" continue ");
            printf("Sua mão:\n");
            for(i=0; i <contador2;i++){
              printf("[%d/%d]",mao2[i][0],mao2[i][1]);
            }
            printf("\nTABULEIRO:\n\n");
             for(i = e; i < d + 1; i++)
             {
                 printf(" [ %d|%d ]" , linha[i][0], linha[i][1]);
             }
           printf("\nEscolha seu movimento\n1-Jogar\n2-Comprar uma peça\n3-Passar sua vez\n4-Salvar e sair\n");
           movimento = lerInteiro();
           if(contador2 == 0){
             printf("Jogador 2 venceu");

           }
           if(movimento == 1){



            if(peca_valida(mao2,linha,contador2,e,d) == 1){
             //Função do Xamuel
             n = JOGO(linha, mao2, e, d);
              if(contador2 == 0){
                 printf("Jogador 2 venceu!");
                exit(0);
              }
             if(n == 0)
             {
               remover(linha[e-1][0], linha[e-1][1],mao2, contador2);
                contador2 --;
               e--;
              rodada ++;
              break;
             }
             else if(n == 1)
             {
               remover(linha[d + 1][0], linha[d + 1][1],mao2, contador2);
                contador2 --;
               if(contador2 == 0){
                  printf("Jogador 2 venceu!");
                 exit(0);
               }
               d++;
              rodada ++;
              break;
             }
             else if(n == 2)
             {
              continue;
             }
            }
            else{
              printf("JOGADA INVALIDA, COMPRE UMA PEÇA!");
            }
           }
           if(movimento == 2){
              if(pecas_no_banco == 0){
                printf("Sem peças disponíveis, jogue ou passe a vez.\n");
              }
              else{
                if(peca_valida(mao2,linha,contador2,e,d) == 1)
                {
                  printf("PEÇAS DISPONIVEIS NA MÃO");
                }
                else
                {
                compra(mao2, mesa, contador2, pecas_no_banco);
                pecas_no_banco --;
                contador2++;
                }
              }
           }
           if(movimento == 3){
             if(peca_valida(mao2,linha,contador2,e,d) != 1 && pecas_no_banco == 0)
             {
              printf("Você passou sua vez!");
              rodada++;
              break;
             }else{
               printf("JOGUE UMA PEÇA OU COMPRE DA MESA");
             }
           }
           if(movimento == 4){
             int escolha;
             printf("Tem certeza que deseja Salvar e Sair?\n1-Sim\n2-Não");
             escolha = lerInteiro();
             if(escolha == 1){
            file = fopen("DOMINO.txt", "w");
              if(file){
                fprintf(file, "%d\n%d\n", contador1, contador2);
                for(int i = 0; i < contador1; i++){
                    fprintf(file, "%d %d ", mao1[i][0], mao1[i][1]);
                }
                fprintf(file, "\n");
                for(int i = 0; i < contador2; i++){
                    fprintf(file, "%d %d ", mao2[i][0], mao2[i][1]);
                }
                fprintf(file, "\n%d\n%d\n%d\n%d\n%d\n", vez1, vez2, rodada, e, d);
                for(i = e; i < d + 1; i++)
           {
             fprintf(file, "%d %d " , linha[i][0], linha[i][1]);
           }
                fprintf(file,"\n");
           for(i = 0; i < 14; i++){
             fprintf(file, "%d ", linhas[i]);
           }     
                fclose(file);
                return 0;
              }
               break;
             }
           }
         }
       }
      }
     }
    }
    if(choice == 2){
      file = fopen("DOMINO.txt", "r+");
      int mao1[21][2],mao2[21][2],linha[55][2],i=0,j,a,linhas[14],aux, e=27, d=27, n, z=0;
          int mesa[28][2]={{0,0},{0,1},{1,1},{2,0},{2,1},{2,2},{3,0},{3,1},{3,2},{3,3},{4,0},{4,1},{4,2},{4,3},{4,4},{5,0},{5,1},{5,2},{5,3},{5,4},{5,5},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{6,6}};
      if(file){
          fscanf(file, "%d", &contador1 );
          fscanf(file, "%d", &contador2 );
          for(int i = 0; i<contador1; i++){
          fscanf(file, "%d %d", &mao1[i][0], &mao1[i][1]);
          }
          for(int i = 0; i<contador2; i++){
          fscanf(file, "%d%d ", &mao2[i][0], &mao2[i][1]);
          }
          fscanf(file, "%d", &vez1 );
          fscanf(file, "%d", &vez2 );
          fscanf(file, "%d", &rodada );
          fscanf(file, "%d", &e );
          fscanf(file, "%d", &d );
          for(i = e; i < d + 1; i++)
           {
             fscanf(file, "%d %d" , &linha[i][0], &linha[i][1]);
           }
          for(i = 0; i < 14; i++){
            fscanf(file, "%d", &linhas[i]);
          }
          fclose(file);
          }
      for(i=0;i<14;i++){
        for(a=0;a<28;a++){
            if(linhas[i] == a){
                do{
                    mesa[a][0] = mesa[a+1][0];
                    mesa[a][1] = mesa[a+1][1];
                    a++;
                }while(a<28);
            }
        }
      }
          if(vez1>vez2){
            rodada++;
            vez1--;
            vez2++;
          }
          else{
            rodada++;
            vez1++;
            vez2--;
          }
          while(loop == 1) {
       if(vez1 == rodada){
         vez1 = vez1 + 2;
         while(loopint == 1){
          if(contador1 == 0){
            printf("\n\n!!!!!JOGADOR 1 VENCEU!!!!!\n\n");
            exit(0);
          }
          else{
          printf("\nRODADA %d\n", rodada);

          printf("\nTurno do jogador 1\n");
          system("read -p \"PRESSIONE ENTER PARA CONTINUAR\" continue ");
          printf("\n\nSua mão:\n\n");
           for(int i=0; i <contador1;i++){
             printf("[%d/%d]",mao1[i][0],mao1[i][1]);
           }
           printf("\nTABULEIRO:\n\n");
           for(i = e; i < d + 1; i++)
           {
             printf(" [ %d|%d ]" , linha[i][0], linha[i][1]);
           }
          printf("\nEscolha seu movimento\n1-Jogar\n2-Comprar uma peça\n3-Passar sua vez\n4-Salvar e sair\n");
          movimento = lerInteiro();

          if(movimento == 1){



            if(peca_valida(mao1,linha,contador1,e,d) == 1){
            //Função do Xamuel

            n = JOGO(linha, mao1, e, d);
            if(n == 0)
             {
               remover(linha[e-1][0], linha[e-1][1],mao1, contador1);
               contador1 --;
               if(contador1 == 0){
                 printf("Jogador 1 venceu");
                 exit(0);
               }
               e--;
              rodada ++;
              break;
             }
             else if(n == 1)
             {
               remover(linha[d + 1][0], linha[d + 1][1],mao1, contador1);
                contador1 --;
               d++;
              rodada ++;
              break;
             }
            else if(n == 2)
             {
              continue;
             }
            }
            else{
              printf("JOGADA INVALIDA, COMPRE UMA PEÇA!\n");
            }
          }

          if(movimento == 2){
            if(pecas_no_banco == 0){
              printf("Sem peças disponíveis, jogue ou passe a vez.\n");
            }
            else{
                if(peca_valida(mao1,linha,contador1,e,d) == 1)
                {
                  printf("PEÇAS DISPONIVEIS NA MÃO");
                }
                else
                {
                compra(mao1, mesa, contador1, pecas_no_banco);
                pecas_no_banco --;
                contador1++;
                }
            }
          }

          if(movimento == 3){
            if(peca_valida(mao1,linha,contador1,e,d) != 1 && pecas_no_banco == 0)
            {
             printf("Você passou sua vez!");
             rodada++;
             break;
            }else{
              printf("JOGUE UMA PEÇA OU COMPRE DA MESA");
            }
          }
          if(movimento == 4){
            int escolha;
            printf("\nTem certeza que deseja Salvar e Sair?\n1-Sim\n2-Não\n");
            escolha = lerInteiro();
            if(escolha == 1){
              file = fopen("DOMINO.txt", "w");
              if(file){
                fprintf(file, "%d\n%d\n", contador1, contador2);
                for(int i = 0; i < contador1; i++){
                    fprintf(file, "%d %d ", mao1[i][0], mao1[i][1]);
                }
                fprintf(file, "\n");
                for(int i = 0; i < contador2; i++){
                    fprintf(file, "%d %d ", mao2[i][0], mao2[i][1]);
                }
                fprintf(file, "\n%d\n%d\n%d\n%d\n%d\n", vez1, vez2, rodada, e, d);
                    for(i = e; i < d + 1; i++)
           {
             fprintf(file, "%d %d " , linha[i][0], linha[i][1]);
           }
                fclose(file);
                return 0;
              }
              break;
            }
          }
          }
        }
       }
        if(vez2 == rodada){
          vez2 = vez2 + 2;
          while(loopint == 1){
            if(contador2 == 0){
              printf("\n\n!!!!!JOGADOR 2 VENCEU!!!!!\n\n");
              exit(0);
            }
            else{
           printf("\nRODADA %d\n", rodada);
           printf("\nTurno do jogador 2\n");
            system("read -p \"PRESSIONE ENTER PARA CONTINUAR\" continue ");
            printf("Sua mão:\n");
            for(i=0; i <contador2;i++){
              printf("[%d/%d]",mao2[i][0],mao2[i][1]);
            }
            printf("\nTABULEIRO:\n\n");
             for(i = e; i < d + 1; i++)
             {
                 printf(" [ %d|%d ]" , linha[i][0], linha[i][1]);
             }
           printf("\nEscolha seu movimento\n1-Jogar\n2-Comprar uma peça\n3-Passar sua vez\n4-Salvar e sair\n");
           movimento = lerInteiro();
           if(contador2 == 0){
             printf("Jogador 2 venceu");

           }
           if(movimento == 1){



            if(peca_valida(mao2,linha,contador2,e,d) == 1){
             //Função do Xamuel
             n = JOGO(linha, mao2, e, d);
              if(contador2 == 0){
                 printf("Jogador 2 venceu!");
                exit(0);
              }
             if(n == 0)
             {
               remover(linha[e-1][0], linha[e-1][1],mao2, contador2);
                contador2 --;
               e--;
              rodada ++;
              break;
             }
             else if(n == 1)
             {
               remover(linha[d + 1][0], linha[d + 1][1],mao2, contador2);
                contador2 --;
               if(contador2 == 0){
                  printf("Jogador 2 venceu!");
                 exit(0);
               }
               d++;
              rodada ++;
              break;
             }
             else if(n == 2)
             {
              continue;
             }
            }
            else{
              printf("JOGADA INVALIDA, COMPRE UMA PEÇA!");
            }
           }
           if(movimento == 2){
              if(pecas_no_banco == 0){
                printf("Sem peças disponíveis, jogue ou passe a vez.\n");
              }
              else{
                if(peca_valida(mao2,linha,contador2,e,d) == 1)
                {
                  printf("PEÇAS DISPONIVEIS NA MÃO");
                }
                else
                {
                compra(mao2, mesa, contador2, pecas_no_banco);
                pecas_no_banco --;
                contador2++;
                }
              }
           }
           if(movimento == 3){
             if(peca_valida(mao2,linha,contador2,e,d) != 1 && pecas_no_banco == 0)
             {
              printf("Você passou sua vez!");
              rodada++;
              break;
             }else{
               printf("JOGUE UMA PEÇA OU COMPRE DA MESA");
             }
           }
           if(movimento == 4){
             int escolha;
             printf("Tem certeza que deseja Salvar e Sair?\n1-Sim\n2-Não");
             escolha = lerInteiro();
             if(escolha == 1){
            file = fopen("DOMINO.txt", "w");
              if(file){
                fprintf(file, "%d\n%d\n", contador1, contador2);
                for(int i = 0; i < contador1; i++){
                    fprintf(file, "%d %d ", mao1[i][0], mao1[i][1]);
                }
                fprintf(file, "\n");
                for(int i = 0; i < contador2; i++){
                    fprintf(file, "%d %d ", mao2[i][0], mao2[i][1]);
                }
                fprintf(file, "\n%d\n%d\n%d\n%d\n%d\n", vez1, vez2, rodada, e, d);
                for(i = e; i < d + 1; i++)
           {
             fprintf(file, "%d %d " , linha[i][0], linha[i][1]);
           }
                fclose(file);
                return 0;
              }
               break;
             }
           }
         }
       }
      }
     }
}
    else if(choice == 3){
      printf(" \nREGRAS DO JOGO \n\n 1- O jogo começa com um conjunto de 28 peças únicas e diferentes, variando de [0|0] até [6|6].\n • Cada jogador começa comprando 7 peças. \n • O jogador inicial é o que possui a dupla mais alta. Se nenhum jogador possuir uma dupla, o que tiver a maior soma inicia. Em caso de empate na soma, o jogador com a peça de maior número em sua composição começa.\n • Em cada vez, o jogador deve realizar uma das três ações: jogar uma peça de sua mão, comprar peças da mesa até que seja possível jogar ou passar a vez, se todas as peças da mesa estiverem esgotadas.\n • As regras para jogar uma peça da mão para a mesa são as seguintes: é permitido jogar peças que tenham um lado com o mesmo número do lado esquerdo da peça mais à esquerda jogada ou um lado com o mesmo número do lado direito da peça mais à direita. Se ambas as possibilidades forem o mesmo número, o jogador pode escolher em que lado quer jogar a peça.\n • Após a jogada, a peça jogada deve se conectar à peça que estava em mesa pelo lado com o número em comum, formando assim uma sequência linear de peças.\n ");
    }
    else if(choice == 4)
    {
      int escolha;
      printf("\nTem certeza que deseja sair para a área de trabalho?\n1-sim\n2-não\n");
      escolha = lerInteiro();
      if(escolha == 1){
      break;
      }
    }
  }
  return 0;
}