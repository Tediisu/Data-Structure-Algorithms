#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    char plateNum[16];
    char owner[32];
    int ticket;
} Car;

typedef Car Dictionary[MAX];

void initParkingList(Dictionary PL);
unsigned int hash(Car data);
void insert(Dictionary PL, Car data);
int findCar(Dictionary PL, Car data);
Car removeCar(Dictionary PL, int nDx);
void populate(Dictionary PL);
void displayList(Dictionary PL);

int main(void) {
  Car c1 = {"MUSC123", "Dominic Toretto", 1523};
  Car c2 = {"SUPR4", "Takashi DK", 7315};
  Dictionary ParkingList;

  initParkingList(ParkingList);
  populate(ParkingList);

  displayList(ParkingList);
  removeCar(ParkingList, findCar(ParkingList, c1));
  removeCar(ParkingList, findCar(ParkingList, c2));
  displayList(ParkingList);


  return 0;
}

void initParkingList(Dictionary PL) {
  for (int i = 0; i < MAX; i++) {
    strcpy(PL[i].plateNum, "");
    strcpy(PL[i].owner, "");
    PL[i].ticket = 0;
  }

}

unsigned int hash(Car data) {
  return (data.ticket * 31 + 31) % MAX;
}

void insert(Dictionary PL, Car data) {
  int nDx = hash(data);
  int flag = nDx;
  printf("\n%d", nDx);
  printf(" >---<[%-10s%-10s%d]", data.plateNum, data.owner, data.ticket);

  while (PL[nDx].ticket != 0) {
    nDx = (nDx + 1) % MAX;
    if (nDx == flag) return;
  }
  PL[nDx] = data;

}

int findCar(Dictionary PL, Car data) {
  int nDx = hash(data);
  int flag = nDx;

  while (PL[nDx].ticket != data.ticket) {
    nDx = (nDx + 1) % MAX;
    if (nDx == flag) return -1;
  }

  return nDx;
}

Car removeCar(Dictionary PL, int nDx) {
  Car temp;
  strcpy(temp.plateNum, PL[nDx].plateNum);
  strcpy(temp.owner, PL[nDx].owner);
  temp.ticket = PL[nDx].ticket;

  strcpy(PL[nDx].plateNum, "");
  strcpy(PL[nDx].owner, "");
  PL[nDx].ticket = 0;

  return temp;
}

void populate(Dictionary PL) {
  Car cars[] = {
      {"MUSC123", "Dominic Toretto", 1523},
      {"SPD789", "Brian O'Conner", 9845},
      {"GT500", "Eleanor Shelby", 3071},
      {"ZL1CAM", "Letty Ortiz", 6259},
      {"R34GTR", "Sean Boswell", 4187},
      {"911TURBO", "Han Lue", 2089},
      {"SUPR4", "Takashi DK", 7315},
      {"CHGR69", "Roman Pearce", 9560},
      {"MSTANG5", "Mia Toretto", 1842},
      {"VETTEZR1", "Tej Parker", 5098},
      {"HELLCAT", "Luke Hobbs", 8730},
      {"NSX2024", "Mr. Nobody", 6904}
  };
  int length = sizeof(cars) / sizeof(cars[0]);

  for (int i = 0; i <  7; i++) {
    insert(PL, cars[i]);
  }

}
void displayList(Dictionary PL) {
  printf("\nParking Area:\n");
  printf("\t%-10s%s\n", "Slot", "Status");
  for (int i = 0; i < MAX; i++) {
    printf("\t%2d", i);
    if (PL[i].ticket != 0) {
      printf("%15s", "[TAKEN]");
      printf(" >---<[%-10s%-15s%d]", PL[i].plateNum, PL[i].owner, PL[i].ticket);
    } else
      printf("%15s", "[EMPTY]");
      printf("\n");
  }
}
