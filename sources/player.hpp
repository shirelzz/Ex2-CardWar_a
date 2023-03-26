class Player{

    private:
        std::string name;

    public:
        Player(std::string name): name(name){}
        //Player:: Player(std::string name): name(name){}

        ~Player(){}

        int stacksize();

        int cardesTaken();




};