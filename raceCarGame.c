#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printIntro();
void printCountDown();
void printFirstPlaceAfterLap(struct Race);
void printCongratulation(struct Race);
int calculateTimeToCompleteLap();
void updateRaceCar(struct RaceCar*);
void updateFirstPlace(struct Race*, struct RaceCar*, struct RaceCar*);
void startRace(struct RaceCar*, struct RaceCar*);


struct Race {
  int numberOfLaps;
  int currentLap;
  char firstPlaceDriverName[25];
  char firstPlaceRaceCarColor[25];
};

struct RaceCar {
  char driverName[25];
  char raceCarColor[25];
  int totalLapTime;
};

void printIntro() {
  printf("Welcome to our main event digital race fans!\n\nI hope everybody has their snacks because we are about to begin!\n\n");
};

void printCountDown() {
  printf("Racers Ready! In...\n5\n4\n3\n2\n1\nRace!\n\n");
};

void printFirstPlaceAfterLap(struct Race race) {
  int currentLap = race.currentLap;
  char* firstPlaceDriverName = race.firstPlaceDriverName;
  char* firstPlaceRaceCarColor = race.firstPlaceRaceCarColor;
  printf("After lap %i\nFirst Place Is: %s in the %s race car!\n\n", currentLap, firstPlaceDriverName, firstPlaceRaceCarColor);
};

void printCongratulation(struct Race race) {
  char* firstPlaceDriverName = race.firstPlaceDriverName;
  char* firstPlaceRaceCarColor = race.firstPlaceRaceCarColor;
  printf("Let's all congratulate %s in the %s race car for an amazing performance.\n\nIt truly was a great race and everybody have a goodnight!\n\n", firstPlaceDriverName, firstPlaceRaceCarColor);
};

int calculateTimeToCompleteLap() {
  int speed = rand() % 3 + 1;
  int acceleration = rand() % 3 + 1;
  int nerves = rand() % 3 + 1;

  return speed + acceleration + nerves;
};

void updateRaceCar(struct RaceCar* raceCar) {
  int lapTime = calculateTimeToCompleteLap();
  (*raceCar).totalLapTime += lapTime;
};

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  char* raceCar1DriverName = (*raceCar1).driverName;
  char* raceCar2DriverName = (*raceCar2).driverName;
  int raceCar1TotalLapTime = (*raceCar1).totalLapTime;
  int raceCar2TotalLapTime = (*raceCar2).totalLapTime;
  char* raceCar1Color = (*raceCar1).raceCarColor;
  char* raceCar2Color = (*raceCar2).raceCarColor;

  if (raceCar1TotalLapTime <= raceCar2TotalLapTime) {
    strcpy((*race).firstPlaceDriverName, raceCar1DriverName);
    strcpy((*race).firstPlaceRaceCarColor, raceCar1Color);
  } else {
    strcpy((*race).firstPlaceDriverName, raceCar2DriverName);
    strcpy((*race).firstPlaceRaceCarColor, raceCar2Color);
  }
};

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {
    .numberOfLaps = 5,
    .currentLap = 1,
    .firstPlaceDriverName = "",
    .firstPlaceRaceCarColor = ""
  };

  for (int i = 0; i < sizeof(race.numberOfLaps)/sizeof(int); i++) {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
  } printCongratulation(race);
}

int main() {
  srand(time(0));

  struct RaceCar raceCar1 = {
    .driverName = "Leah",
    .raceCarColor = "Blue",
    .totalLapTime = 0
  };

  struct RaceCar raceCar2 = {
    .driverName = "Josh",
    .raceCarColor = "Green",
    .totalLapTime = 0
  };

  printIntro();
  printCountDown();
  startRace(&raceCar1, &raceCar2);
  
};