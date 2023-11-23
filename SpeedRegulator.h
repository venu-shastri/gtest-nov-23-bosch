
class SpeedRegulator 
{
    public:
        void regulate(int speed);
        private:
        void increase(int speed);
 
        
        void decrease(int speed);
 
    private:
 
       int threshold;
};