type location = {
  lat : int,
  lon : int,
};

type user = {
  username : string,
  location : location,
};

type state = { 
  users : option(array(user)),
};

type action = 
  | Get
  | Loading
  | SetUsers(array(user));
