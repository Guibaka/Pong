class Score{
    public : 
        Score(int width, int height);
        int get_width();
        int get_height();
        int get_score_left();
        int get_score_right();
        void plus_one(bool isRight);
    private : 
        int width;
        int height;
        int score_left;
        int score_right;
};