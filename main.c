#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int white='W'; //white ������ W ���� 
int black='B'; // black������ B���� 
int white_cnt=2;  // �����ǿ� ����  ��� �ٵϵ� ����  
int black_cnt=2;  // �����ǿ� ���� ������ �ٵϵ� ����  

int printBoard(int gameboard[6][6]){ //������ ����� �Լ�  
		
	int i, j;          //���� i,j ����  

	gameboard[2][2]=white; // gameboard 2,2�� ��ٵϵ� ��ġ 
	gameboard[3][3]=white; //gameboard 3,3�� ��ٵϵ� ��ġ 
	gameboard[2][3]=black; //gameboard 2,3�� ���� �ٵϵ� ��ġ 
	gameboard[3][2]=black; //gameboard 3,2��  ���� �ٵϵ� ��ġ  
	
	printf("------------\n");
	
	for(i=0;i<6;i++){          //6X6 ��� ����� 
		for(j=0;j<6;j++){
			
			printf("%c|", gameboard[i][j]); //��� ���  
		}
		printf("\n");
		printf("------------\n");
	}

}

int checkFlip(int startX, int startY, int wayX, int wayY, int color) ;

int main(int argc, char *argv[]) {
	
	int x,y;   //���� x,y ���� 
	int player=1; //�÷��̾� ���� ����  
    int gameboard[6][6]={}; // gameboard�迭 �μ� ���� 
    int flag_turnEnd; //���ʰ� ������ �� �ƴ����� �˷��ִ� ���� �� ��  
    
    
    while (1) { // ���� �ݺ�  
	    flag_turnEnd = 0;
	    printBoard(gameboard); //printBoard�Լ� ȣ��  
	   		
		printf("STATUS- WHITE: %d, BLACK: %d\n", white_cnt, black_cnt); //��, �� �ٵϵ� ���� ��Ÿ����  
	    
		if (player==1){
	        printf("put a new white othello: \n"); //�� �ٵϵ����� ��ġ  �Է��϶�� ���   
	    }
	    else
	    {
	    	printf("put a new black othello: \n"); //������  �ٵϵ����� ��ġ  �Է��϶�� ���   
	    }
    	scanf("%d %d", &y, &x); // �� �ٵϵ� ���� ��ǥ �Է¹ޱ�  
    	
    	if(gameboard[y-1][x-1]!=white&& gameboard[y-1][x-1]!=black){ //�Է¹��� ��ǥ�� ��, �� �ٵϵ��� ���� ���̶�� ����  
    		
    		printBoard(gameboard); //gameboardȣ��  
    		if (player == 1)
    	    	gameboard[y-1][x-1]=white; //�Է¹��� ��ǥ�� �� �ֱ�  
    		else
    			gameboard[y-1][x-1]=black; //�Է¹��� ��ǥ�� ������ �ֱ�   
    		
    		flag_turnEnd = 1;
    	}
    	else if(y>5|| x>5|| y<0|| x<0){
		      printf("invalid input! (should be less than 6)");
		}  
    
		if (flag_turnEnd == 1)
			player = (player + 1)%2; //���� �ٲٱ� ���:1, ������:0  
	}
	return 0;
}
