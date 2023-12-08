struct Pilot{
    const char* name;
};

struct Weapon {
    int munition;
    int damage;
};

struct Wing {
    Weapon laser;
    Weapon rockets;
};

struct Mothership
{
    Pilot pilots [2];
    Wing* wings[4];
};

class Spaceship{
    public:
    Mothership* mother;
    Pilot& shipPilot;
    Wing* left;
    Wing* right;

    Spaceship(Mothership* motherShip, Pilot& pilot, Wing* leftWing, Wing* rightWing)
        : mother(motherShip), shipPilot(pilot), left(leftWing), right(rightWing) {}

};

int main() {
    // Example usage
    Pilot pilot1 = { "Pilot 1" };
    Pilot pilot2 = { "Pilot 2" };

    Wing wing1;
    Wing wing2;

    Mothership mother;
    mother.pilots[0] = pilot1;
    mother.pilots[1] = pilot2;
    mother.wings[0] = &wing1;
    mother.wings[1] = &wing2;

    

    Spaceship* child = new Spaceship(&mother, pilot1, &wing1, &wing2);

    child->right->rockets.munition;
    mother.pilots[1].name;

    (*child).mother->wings[3]->laser; // Weapon
    (&mother)->wings[0]->rockets; //Weapon
    (&mother)->pilots; // Pilot[]
    &(*child).left->laser; // Weapon
    &child->left; // Wing*

    // pilot[2]; == *(pilot+2);
    delete child;
    return 0;
}