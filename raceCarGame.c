
/*

Example Play:


Welcome to our main event digital race fans!
I hope everybody has their snacks because we are about to begin!

Racers Ready! In...
5
4
3
2
1
Race!

After lap 1
First Place Is: Leah in the blue race car!

After lap 2
First Place Is: Josh in the green race car!

After lap 3
First Place Is: Josh in the green race car!

After lap 4
First Place Is: Leah in the blue race car!

After lap 5
First Place Is: Josh in the green race car!

Let's all congratulate our winner, Josh in the green race car for an amazing performance.

It truly was a great race and everybody have a goodnight!

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
  printf("Welcome to our main event digital race fans!\nI hope everybody has their snacks because we are about to begin!\n\n");
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

  if ((*raceCar1).totalLapTime <= (*raceCar2).totalLapTime) {
    strcpy((*race).firstPlaceDriverName, (*raceCar1).driverName);
    strcpy((*race).firstPlaceRaceCarColor, (*raceCar1).raceCarColor);
  } else {
    strcpy((*race).firstPlaceDriverName, (*raceCar2).driverName);
    strcpy((*race).firstPlaceRaceCarColor, (*raceCar2).raceCarColor);
  }

};

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {
    .numberOfLaps = 5,
    .currentLap = 1,
    .firstPlaceDriverName = "",
    .firstPlaceRaceCarColor = ""
  };

  for (int i = race.currentLap; i <= race.numberOfLaps; i++) {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
    race.currentLap += 1;
  } printCongratulation(race);
}

int main() {
  srand(time(0));

  struct RaceCar raceCar1 = {
    .driverName = "Leah",
    .raceCarColor = "blue",
    .totalLapTime = 0
  };

  struct RaceCar raceCar2 = {
    .driverName = "Josh",
    .raceCarColor = "green",
    .totalLapTime = 0
  };

  printIntro();
  printCountDown();
  startRace(&raceCar1, &raceCar2);
  
};


/*

Example Play:


Welcome to our main event digital race fans!
I hope everybody has their snacks because we are about to begin!

Racers Ready! In...
5
4
3
2
1
Race!

After lap 1
First Place Is: Leah in the blue race car!

After lap 2
First Place Is: Josh in the green race car!

After lap 3
First Place Is: Josh in the green race car!

After lap 4
First Place Is: Leah in the blue race car!

After lap 5
First Place Is: Josh in the green race car!

Let's all congratulate our winner, Josh in the green race car for an amazing performance.

It truly was a great race and everybody have a goodnight!

*/