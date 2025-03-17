#define P11 13
#define P12 12
#define P13 11
#define P21 10
#define P22 9
#define P23 8
#define P31 7
#define P32 6
#define P33 5

int current_player = 1;
int p11, p12, p13 = 0;
int p21, p22, p23 = 0;
int p31, p32, p33 = 0;
int blink_position[20] = {0};
int contor = 0;
unsigned long lastMillis = 0;
int blinking = 0;
int player_1_matrix[10] = {0};
int player_2_matrix[10] = {0};
int m1 = 0;
int m2 = 0;
bool gameOver = false;

int player_1_score = 0; 
int player_2_score = 0;

void setup() {
  pinMode(13, OUTPUT); 
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  Serial.println("Scrie pozitia din matrice unde vrei sa pozitionezi piesa. Ex: 11 pentru linia 1 si coloana 1.");
}

void loop() {

  if (gameOver) {
    if (Serial.available() > 0) {
      int input = Serial.parseInt();
      if (input == 100) { 
        resetGame();
      } else {
        Serial.println("Scrie '100' pentru a incepe un nou joc.");
      }
    }
    return; 
  }

  if (Serial.available() > 0) {
    int input = Serial.parseInt();
    int c = 0;

    if (castigator_pe_diagonala(player_2_matrix, m2) || castigator_pe_linie(player_2_matrix, m2) || castigator_pe_coloana(player_2_matrix, m2)) {
      Serial.println("\nJucatorul 2 a castigat!");

      player_2_score++;

      Serial.print("Scor: Player 1 - ");
      Serial.print(player_1_score);
      Serial.print(" | Player 2 - ");
      Serial.println(player_2_score);

      gameOver = true; 
      Serial.println("Scrie '100' pentru a incepe un nou joc.");
      return;
    }else if (castigator_pe_diagonala(player_1_matrix, m1) || castigator_pe_linie(player_1_matrix, m1) || castigator_pe_coloana(player_1_matrix, m1)) {
      Serial.println("\nJucatorul 1 a castigat!");

      player_1_score++;

      Serial.print("Scor: Player 1 - ");
      Serial.print(player_1_score);
      Serial.print(" | Player 2 - ");
      Serial.println(player_2_score);

      gameOver = true; 
      Serial.println("Scrie '100' pentru a incepe un nou joc.");
      return;
    }else if (m1 + m2 == 9) {
      Serial.println("\nRemiza!");

      Serial.print("Scor: Player 1 - ");
      Serial.print(player_1_score);
      Serial.print(" | Player 2 - ");
      Serial.println(player_2_score);

      gameOver = true; 
      Serial.println("Scrie '100' pentru a incepe un nou joc.");
      return;

    }

    if (input == 100 && gameOver) {
      resetGame();
      return;
    }
    
    if (current_player == 1) {
      Serial.println("\n");
        Serial.println("\nAcum muta player1.\n");
        Serial.flush();
        c = 1;
    }else {
      Serial.println("\n");
      Serial.println("\nAcum muta player2.\n");
      Serial.flush();
      c = 2;
      blinking = 1;
    }

    if (input == 11) {
      if (p11 == 0) {
        digitalWrite(13, HIGH); 
        Serial.print("Jucatorul ");
        Serial.print(c);
        Serial.print(" a mutat la pozitia ");
        Serial.print(input);
        change_player(current_player);
        p11 = 1;

        if (c == 2) {
          blink_position[P11] = 1;
          player_2_matrix[m2++] = 13;

        }else {
          player_1_matrix[m1++] = 13;
        }

      }else if (p11 == 1) {
        Serial.print("\nPozitia ");
        Serial.print(input);
        Serial.print(" este ocupata.");
      }

    }else if (input == 12) {
      if (p12 == 0) {
        digitalWrite(12, HIGH); 
        Serial.print("Jucatorul ");
        Serial.print(c);
        Serial.print(" a mutat la pozitia ");
        Serial.print(input);
        change_player(current_player);
        p12 = 1;

        if (c == 2) {
          blink_position[P12] = 1;
          player_2_matrix[m2++] = 12;
        }else {
          player_1_matrix[m1++] = 12;
        }
        
      }else if (p12 == 1) {
        Serial.print("\nPozitia ");
        Serial.print(input);
        Serial.print(" este ocupata.");
      }

    }else if (input == 13) {
      if (p13 == 0) {
        digitalWrite(11, HIGH); 
        Serial.print("Jucatorul ");
        Serial.print(c);
        Serial.print(" a mutat la pozitia ");
        Serial.print(input);
        change_player(current_player);
        p13 = 1;

        if (c == 2) {
          blink_position[P13] = 1;
          player_2_matrix[m2++] = 11;
        }else {
          player_1_matrix[m1++] = 11;
        }
        
      }else if (p13 == 1) {
        Serial.print("\nPozitia ");
        Serial.print(input);
        Serial.print(" este ocupata.");
      }

    }else if (input == 21) {
      if (p21 == 0) {
        digitalWrite(10, HIGH); 
        Serial.print("Jucatorul ");
        Serial.print(c);
        Serial.print(" a mutat la pozitia ");
        Serial.print(input);
        change_player(current_player);
        p21 = 1;

        if (c == 2) {
          blink_position[P21] = 1;
          player_2_matrix[m2++] = 10;
        }else {
          player_1_matrix[m1++] = 10;
        }
        
      }else if (p21 == 1) {
        Serial.print("\nPozitia ");
        Serial.print(input);
        Serial.print(" este ocupata.");
      }

    }else if (input == 22) {
      if (p22 == 0) {
        digitalWrite(9, HIGH); 
        Serial.print("Jucatorul ");
        Serial.print(c);
        Serial.print(" a mutat la pozitia ");
        Serial.print(input);
        change_player(current_player);
        p22 = 1;

        if (c == 2) {
          blink_position[P22] = 1;
          player_2_matrix[m2++] = 9;
        }else {
          player_1_matrix[m1++] = 9;
        }
        
      }else if (p22 == 1) {
        Serial.print("\nPozitia ");
        Serial.print(input);
        Serial.print(" este ocupata.");
      }

    }else if (input == 23) {
      if (p23 == 0) {
        digitalWrite(8, HIGH); 
        Serial.print("Jucatorul ");
        Serial.print(c);
        Serial.print(" a mutat la pozitia ");
        Serial.print(input);
        change_player(current_player);
        p23 = 1;

        if (c == 2) {
          blink_position[P23] = 1;
          player_2_matrix[m2++] = 8;
        }else {
          player_1_matrix[m1++] = 8;
        }
        
      }else if (p23 == 1) {
        Serial.print("\nPozitia ");
        Serial.print(input);
        Serial.print(" este ocupata.");
      }

    }else if (input == 31) {
      if (p31 == 0) {
        digitalWrite(7, HIGH); 
        Serial.print("Jucatorul ");
        Serial.print(c);
        Serial.print(" a mutat la pozitia ");
        Serial.print(input);
        change_player(current_player);
        p31 = 1;

        if (c == 2) {
          blink_position[P31] = 1;
          player_2_matrix[m2++] = 7;
        }else {
          player_1_matrix[m1++] = 7;
        }
        
      }else if (p31 == 1) {
        Serial.print("\nPozitia ");
        Serial.print(input);
        Serial.print(" este ocupata.");
      }

    }else if (input == 32) {
      if (p32 == 0) {
        digitalWrite(6, HIGH); 
        Serial.print("Jucatorul ");
        Serial.print(c);
        Serial.print(" a mutat la pozitia ");
        Serial.print(input);
        change_player(current_player);
        p32 = 1;

        if (c == 2) {
          blink_position[P32] = 1;
          player_2_matrix[m2++] = 6;
        }else {
          player_1_matrix[m1++] = 6;
        }
        
      }else if (p32 == 1) {
        Serial.print("\nPozitia ");
        Serial.print(input);
        Serial.print(" este ocupata.");
      }

    }else if (input == 33) {
      if (p33 == 0) {
        digitalWrite(5, HIGH); 
        Serial.print("Jucatorul ");
        Serial.print(c);
        Serial.print(" a mutat la pozitia ");
        Serial.print(input);
        change_player(current_player);
        p33 = 1;

        if (c == 2) {
          blink_position[P33] = 1;
          player_2_matrix[m2++] = 5;
        }else {
          player_1_matrix[m1++] = 5;
        }
        
      }else if (p33 == 1) {
        Serial.print("\nPozitia ");
        Serial.print(input);
        Serial.print(" este ocupata.");
      }

    }else if (input != 0) {                          
      Serial.println("Comanda invalida. Introduceti o pozitie valida.");
    }

  }


  if (blinking == 1) {
    unsigned long currentMillis = millis();

    if (currentMillis - lastMillis >= 200) {
        lastMillis = currentMillis;

        for (int i = 0; i < 20; i++) {
          if (blink_position[i] == 1)
            digitalWrite(i, !digitalRead(i));
        }
    }

  }
}

void change_player(int &current_player){
  if (current_player == 1) {
      current_player = 2;
  }else if (current_player == 2) {
      current_player = 1;
  }
}

bool castigator_pe_diagonala(int matrix[], int m){
  bool gasit_5 = false;
  bool gasit_9 = false;
  bool gasit_13 = false;
  bool gasit_7 = false;
  bool gasit_11 = false;

  for (int i = 0; i < m; i++) {
    if (matrix[i] == 5) {
      gasit_5 = true;
    }else if (matrix[i] == 7) {
      gasit_7 = true;
    }else if (matrix[i] == 9) {
      gasit_9 = true;
    }else if (matrix[i] == 11) {
      gasit_11 = true;
    }else if (matrix[i] == 13) {
      gasit_13 = true;
    }
  }

  if (gasit_5 == true && gasit_9 == true && gasit_13 == true) {
    Serial.println("\nCombinatia castigatoare este: 11, 22, 33");
    allLedsUp(5, 9, 13);
    return true;
  }else if (gasit_7 == true && gasit_9 == true && gasit_11 == true) {
    Serial.println("\nCombinatia castigatoare este: 13, 22, 31");
     allLedsUp(7, 9, 11);
    return true;
  }else return false;
}

bool castigator_pe_linie(int matrix[], int m){
  bool gasit_5 = false;
  bool gasit_6 = false;
  bool gasit_7 = false;
  bool gasit_8 = false;
  bool gasit_9 = false;
  bool gasit_10 = false;
  bool gasit_11 = false;
  bool gasit_12 = false;
  bool gasit_13 = false;

  for (int i = 0; i < m; i++) {
    if (matrix[i] == 5) {
      gasit_5 = true;
    }else if (matrix[i] == 6){
      gasit_6 = true;
    }else if (matrix[i] == 7) {
      gasit_7 = true;
    }else if (matrix[i] == 8) {
      gasit_8 = true;
    }else if (matrix[i] == 9) {
      gasit_9 = true;
    }else if (matrix[i] == 10) {
      gasit_10 = true;
    }else if (matrix[i] == 11) {
      gasit_11 = true;
    }else if (matrix[i] == 12) {
      gasit_12 = true;
    }else if (matrix[i] == 13) {
      gasit_13 = true;
    }
  }

  if (gasit_13 == true && gasit_12 == true && gasit_11 == true) {
    Serial.println("\nCombinatia castigatoare este: 11, 12, 13");
     allLedsUp(11, 12, 13);
    return true;
  }else if (gasit_10 == true && gasit_9 == true && gasit_8 == true) {
    Serial.println("\nCombinatia castigatoare este: 21, 22, 23");
     allLedsUp(8, 9, 10);
    return true;
  }else if (gasit_7 == true && gasit_6 == true && gasit_5 == true) {
    Serial.println("\nCombinatia castigatoare este: 31, 32, 33");
     allLedsUp(5, 6, 7);
    return true;
  }else return false;
}

bool castigator_pe_coloana(int matrix[], int m){
  bool gasit_5 = false;
  bool gasit_6 = false;
  bool gasit_7 = false;
  bool gasit_8 = false;
  bool gasit_9 = false;
  bool gasit_10 = false;
  bool gasit_11 = false;
  bool gasit_12 = false;
  bool gasit_13 = false;

  for (int i = 0; i < m; i++) {
    if (matrix[i] == 5) {
      gasit_5 = true;
    }else if (matrix[i] == 6){
      gasit_6 = true;
    }else if (matrix[i] == 7) {
      gasit_7 = true;
    }else if (matrix[i] == 8) {
      gasit_8 = true;
    }else if (matrix[i] == 9) {
      gasit_9 = true;
    }else if (matrix[i] == 10) {
      gasit_10 = true;
    }else if (matrix[i] == 11) {
      gasit_11 = true;
    }else if (matrix[i] == 12) {
      gasit_12 = true;
    }else if (matrix[i] == 13) {
      gasit_13 = true;
    }
  }

  if (gasit_13 == true && gasit_10 == true && gasit_7 == true) {
    Serial.println("\nCombinatia castigatoare este: 11, 21, 31");
     allLedsUp(7, 10, 13);
    return true;
  }else if (gasit_12 == true && gasit_9 == true && gasit_6 == true) {
    Serial.println("\nCombinatia castigatoare este: 12, 22, 32");
     allLedsUp(6, 9, 12);
    return true;
  }else if (gasit_11 == true && gasit_8 == true && gasit_5 == true) {
    Serial.println("\nCombinatia castigatoare este: 13, 23, 33");
     allLedsUp(5, 8, 11);
    return true;
  }else return false;
}

void resetGame() {
  for (int i = 5; i <= 13; i++) {
    digitalWrite(i, LOW);
  }

  p11 = p12 = p13 = 0;
  p21 = p22 = p23 = 0;
  p31 = p32 = p33 = 0;

  m1 = m2 = 0;

  for (int i = 0; i < 10; i++) {
    player_1_matrix[i] = 0;
    player_2_matrix[i] = 0;
  }

  for (int i = 0; i < 20; i++) {
    blink_position[i] = 0;
  }

  blinking = false; 
  gameOver = false; 
  current_player = 1; 
  Serial.println("Incepe o noua runda. Player 1 incepe!");
}

void allLedsUp(int l1, int l2, int l3) {
  for (int i = 5; i <= 13; i++) {
    if (i != l1 && i != l2 && i != l3) {
      digitalWrite(i, LOW);
    }else {
      digitalWrite(i, HIGH);
    }
  }

}
