#include <stdio.h>
#include <time.h>


typedef struct card {
   int num;
   char shape;
}card;

typedef struct player {
   card deck[27];
   char name[20];
}player;

int catching_thief() {
   int deck[53];
   player player1, player2;
   card cardData;
   
   
   //player 이름 설정 함수

   suffle(deck);
   pushDeck(deck, player1, player2);
   sort(player1.deck);      //소팅 후 정리 
   sort(player2.deck);

   //통신 준비완료 
   while (!isClear(player1.deck) && !isClaer(player2.deck)) {

      cardData = player1Turn(player2.deck); //플1에게 전송 후 데이터 받아오기
      pushCard(player1, cardData);         //카드 삽입
      sort(player1.deck);                  //시간복잡도 고려해서 수정할 필요있음
      if (isClear(player1.deck))            //끝났는지 체크
         break;
      cardData = player2Turn(player1.deck); 
      pushCard(player2, cardData);         
      sort(player2.deck);                  
   }

   if (isClear(player1.deck))
   {
      display_win_player1();      //player1에게 승리 화면
      display_lose_player2();      //player2 에게 패배 화면
      changeRecord();            //기록 수정 - file IO
   }

   return 0;
}
int main() {



   return 0;
}
