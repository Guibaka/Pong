class Ball{
    private : 
        float position_x;
        float position_y;
        float direction_x;
        float direction_y;
        int ball_speed;
        int ball_rayon;
        void vec2_norm(float x, float y);
    public :
        Ball(int r, float x, float y, float dir_x, float dir_y);
        float get_position_x();
        float get_position_y();
        float get_direction_x();
        float get_direction_y();
        int get_rayon();
        void update_direction(float dir_x, float dir_y);
        void update_position();
        void reset();
};