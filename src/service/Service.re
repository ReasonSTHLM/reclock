/*
  Code for backend goes here.

  Assignment: Create an HTTP server running on port 2112 which
  responds with the JSON representation of our Model.t with:
    time: the timestamp of the current time,
    lang: a language of your choice (some ideas: hardcode it / randomise / determined from headers...)

  You can test if your server works by:
    curl localhost:2112

    or

    using the frontend: http://localhost:8080/src/client/
 */

type app;

[@bs.module "express"] external express : unit => app = "express";
