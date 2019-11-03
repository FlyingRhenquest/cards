This is a project for exploring a couple things. Cards have been done to death, but they're also reasonably well
understood, so I can focus on the stuff I'm interested in learning.

So what am I interested in learning?

 1. Imgui -- I haven't done a lot of UI work and Imgui looks interesting. I'm still trying to figure out the
    best way to import his code since he doesn't seem to be in to building libraries. It looks like the general
    method is to just copy all his code to your repo, which feels a bit weird to me. Might be OK if I just
    document where those bits are coming from, I guess.

 2. PyBind11 -- Expose Python API for C++ objects.

 3. Serialization. Commonly I've been using Boost::Ptree but I'd like to take a crack at RapidJSON. It's going
    to be manual at the moment. At some point I want to write a GCC plugin to handle it, but that's a fairly
    big project and I'd want some time to focus on it.

 4. The C++ to Webasm pipeline. It looks like Imgui compiles to Webasm pretty well, and passing serialized
    cards from server to a webasm client would be pretty neat.

I'm going to check this project in before I've done most of that. Currently the library is very simple and
only has a python library interface, but that's enough to start playing with it now. I plan to add the other
stuff to it over the course of the next few weeks, as there are some upcoming holidays that'll be great for
doing some development.