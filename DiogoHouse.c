#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
    
    
int main () 
{
  setlocale(LC_ALL,"Portuguese");
  
    int ativo = 1;
    char mapaRender[1000] = "";

    char direcao[5] = "nada";
    int playerX = 0;
    int playerY = 0;
    int ganhou = 0;

    /*
       0- nada
       1- parede
       8- player
       9- casa do Diogo
    */
    
    //troque o mapa aqui.
    int mapaX = 8;
    int mapaY = 5;
    int data[5][8] = {
        {8,0,1,1,0,0,0,1},
        {1,0,1,1,0,1,0,1},
        {1,0,1,1,0,1,9,1},
        {1,0,1,0,0,1,1,1},
        {1,0,0,0,1,1,1,1}
    };
    //////////////////////////

    int loadY = 0;
    while (loadY < mapaY) 
    {
        int loadX = 0;
        while (loadX < mapaX) 
        {
            if (data[loadY][loadX] == 8) 
            {
                playerX = loadX;
                playerY = loadY;
            }
            loadX = loadX + 1;
        }
        loadY = loadY + 1;
    }

    while (ativo == 1) 
    {
        system("clear");
        printf("Casa do DiogoTv: \n");
        strcpy(mapaRender, "");
        int loopY = 0;
        while (loopY < mapaY) 
        {
            int loopX = 0;
            while (loopX < mapaX) 
            {
                int obj = data[loopY][loopX];

                char maisMapa[3] = "";
                if (obj == 9) 
                {
                    strcpy(maisMapa, "A ");
                    if (playerX == loopX && playerY == loopY)
                        ganhou = 1;
                } 
                else 
                {
                    if (obj == 1)
                        strcpy(maisMapa, "/ ");
                    else 
                    {
                        if (playerY == loopY && playerX == loopX)
                            strcpy(maisMapa, "O ");
                        else 
                        {
                            if ((loopX + loopY) % 2 == 0)
                                strcpy(maisMapa, ". ");
                            else
                                strcpy(maisMapa, ", ");
                        }
                    }
                }

                strcat(mapaRender, maisMapa);
                loopX = loopX + 1;
            }
            strcat(mapaRender, "\n");
            loopY = loopY + 1;
        }
        if (ganhou) 
        {
            printf("VOCÊ GANHOU!!\n\nO Diogo te odeia agora. '-'\n");
            ativo = 0;
        } 
        else 
        {
            printf("%s", mapaRender);
            printf("direção: (w/a/s/d): ");
            scanf("%s", direcao);
            
            int i = 0;
            while (direcao[i]) 
            {
                direcao[i] = tolower(direcao[i]);
                i++;
            }
        }

        int nPlayerX = playerX;
        int nPlayerY = playerY;
        if (strcmp(direcao, "w") == 0)
            nPlayerY = nPlayerY - 1;
        if (strcmp(direcao, "s") == 0)
            nPlayerY = nPlayerY + 1;
        if (strcmp(direcao, "a") == 0)
            nPlayerX = nPlayerX - 1;
        if (strcmp(direcao, "d") == 0)
            nPlayerX = nPlayerX + 1;
      
        if (nPlayerX < 0)
            nPlayerX = 0;
        if (nPlayerX >= mapaX)
            nPlayerX = mapaX - 1;
        if (nPlayerY < 0)
            nPlayerY = 0;
        if (nPlayerY >= mapaY)
            nPlayerY = mapaY - 1;
      
        if (data[nPlayerY][nPlayerX] != 1) 
        {
            playerX = nPlayerX;
            playerY = nPlayerY;
        }
    }
    return 0;
}

//mapas aqui em baixo, só trocar no codigo.
    
    /*
    
    mapa 00-principal
    
    int mapaX = 8;
    int mapaY = 5;
    int data[5][8] = {
        {8,0,1,1,0,0,0,1},
        {1,0,1,1,0,1,0,1},
        {1,0,1,1,0,1,9,1},
        {1,0,1,0,0,1,1,1},
        {1,0,0,0,1,1,1,1}
    };
    
    */
    
    /*  
    
    //mapa 01
    
    int mapaX = 12;
    int mapaY = 5;
    int data[5][12] = {
      {8,0,1,1,1,0,0,0,1,1,1,1},
      {1,0,1,0,0,0,1,0,1,1,0,9},
      {0,0,1,0,1,1,1,0,1,0,0,1},
      {0,1,1,0,1,1,1,0,1,0,1,1},
      {0,0,0,0,1,1,1,0,0,0,1,1}
    };
    
    */
    
    /*
    
    //mapa 02
    
    int mapaX = 7;
    int mapaY = 5;
    int data[5][7] = {
      {8,0,1,0,1,0,9},
      {0,0,1,0,1,0,0},
      {1,0,0,0,0,0,1},
      {0,1,0,0,0,1,0},
      {0,0,1,1,1,0,0}
    };
    
    */
    
    
    /*
    
    //mapa 03
    
    int mapaX = 14;
    int mapaY = 9;
    int data[9][14] = {
      {0,0,0,0,0,0,0,0,0,1,1,1,1,0},
      {0,0,0,0,0,0,0,0,1,0,0,0,0,1},
      {0,1,1,1,1,1,1,1,1,0,0,0,0,1},
      {1,0,0,0,0,0,0,0,1,0,0,0,0,1},
      {1,0,0,0,0,0,0,0,0,1,1,1,1,0},
      {1,0,0,0,0,0,0,0,1,0,0,0,0,1},
      {0,1,1,1,1,1,1,1,1,0,0,0,0,1},
      {0,0,0,0,0,0,0,0,1,0,0,0,0,1},
      {8,0,0,9,0,0,0,0,0,1,1,1,1,0}
    };
    
    */
    
    /*
    
    //mapa 04
    
    int mapaX = 7;
    int mapaY = 5;
    int data[5][7] = {
      {8,0,0,0,0,0,0},
      {0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0},
      {0,0,0,0,0,0,9}
    };
    
    */
