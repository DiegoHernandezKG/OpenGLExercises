#ifndef APPLICATION_HPP
#define APPLICATION_HPP

//TODO: Actually implement this
class Application
{
    public:
        void run()
        {
            init();
            preproc();
            mainloop();
            cleanup();
        }
    private:
        void init();
        void preproc();
        void mainloop();
        void cleanup();
};

#endif