class Racket{
    private :
        int racket_height;
        int racket_width;
        int racket_speed;
        float position_x;
        float position_y;

    public :
        Racket(int width, int height, float x, float y);
        int get_height();
        int get_width();
        int get_speed();
        int get_position_x();
        int get_position_y();
        void move_up();
        void move_down();
};