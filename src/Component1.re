let component = ReasonReact.reducerComponent("Page");

let make = (~message, _children) => {
  ...component,

  initialState: (): Model.state => { users : None },

  reducer: (action, state: Model.state) =>
    switch (action) {
      | Model.SetUsers(users) => {ReasonReact.Update({ users: Some(users)})}
      | Model.Get => {
        ReasonReact.UpdateWithSideEffects(
          state,
          (self => {
            Data.get() |> Js.Promise.then_(users => {
              Js.Promise.resolve(self.send(Model.SetUsers(users)));
            }) |> ignore;
          }
          )
        );
      };
    },

  render: self => {
    let s : Model.state = self.state;
    let u : option(array(Model.user)) = s.users;
    <div>
      <button onClick=((e) => self.send(Model.Get))>((ReasonReact.string("cliiick")))</button>
      <div>(
        switch(u) {
          | Some(users) => {
            ReasonReact.arrayToElement(
              Array.map((user: Model.user) => <div key={user.username}>(ReasonReact.string(user.username))</div>, users))
          };
          | None => { ReasonReact.string("No users") };
          }
      )
      </div>
      </div>
  },
};
