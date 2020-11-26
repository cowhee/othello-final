#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int white='W'; //white 변수에 W 대입 
int black='B'; // black변수에 B대입 
int white_cnt=2;  // 게임판에 놓인  흰색 바둑돌 개수  
int black_cnt=2;  // 게임판에 놓인 검은색 바둑돌 개수  

int printBoard(int gameboard[6][6]){ //게임판 만드는 함수  
		
	int i, j;          //변수 i,j 선언  

	gameboard[2][2]=white; // gameboard 2,2에 흰바둑돌 배치 
	gameboard[3][3]=white; //gameboard 3,3에 흰바둑돌 배치 
	gameboard[2][3]=black; //gameboard 2,3에 검은 바둑돌 배치 
	gameboard[3][2]=black; //gameboard 3,2에  검은 바둑돌 배치  
	
	printf("------------\n");
	
	for(i=0;i<6;i++){          //6X6 행렬 만들기 
		for(j=0;j<6;j++){
			
			printf("%c|", gameboard[i][j]); //행렬 출력  
		}
		printf("\n");
		printf("------------\n");
	}

}

int checkFlip(int startX, int startY, int wayX, int wayY, int color) ;

int main(int argc, char *argv[]) {
	
	int x,y;   //변수 x,y 선언 
	int player=1; //플레이어 변수 선언  
    int gameboard[6][6]={}; // gameboard배열 인수 선언 
    int flag_turnEnd; //차례가 끝났는 지 아닌지를 알려주는 변수 선 언  
    
    
    while (1) { // 차례 반복  
	    flag_turnEnd = 0;
	    printBoard(gameboard); //printBoard함수 호출  
	   		
		printf("STATUS- WHITE: %d, BLACK: %d\n", white_cnt, black_cnt); //흰, 검 바둑돌 개수 나타내기  
	    
		if (player==1){
	        printf("put a new white othello: \n"); //흰 바둑돌놓을 위치  입력하라고 출력   
	    }
	    else
	    {
	    	printf("put a new black othello: \n"); //검은색  바둑돌놓을 위치  입력하라고 출력   
	    }
    	scanf("%d %d", &y, &x); // 흰 바둑돌 놓을 좌표 입력받기  
    	
    	if(gameboard[y-1][x-1]!=white&& gameboard[y-1][x-1]!=black){ //입력받은 좌표가 흰, 검 바둑돌이 없는 곳이라는 조건  
    		
    		printBoard(gameboard); //gameboard호출  
    		if (player == 1)
    	    	gameboard[y-1][x-1]=white; //입력받은 좌표에 흰돌 넣기  
    		else
    			gameboard[y-1][x-1]=black; //입력받은 좌표에 검은돌 넣기   
    		
    		flag_turnEnd = 1;
    	}
    	else if(y>5|| x>5|| y<0|| x<0){
		      printf("invalid input! (should be less than 6)");
		}  
    
		if (flag_turnEnd == 1)
			player = (player + 1)%2; //차례 바꾸기 흰색:1, 검은색:0  
	}
	return 0;
}
