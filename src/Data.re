let server = "https://immense-river-25513.herokuapp.com/locations";

[@bs.val] [@bs.scope "JSON"]
external parse : string => array(Model.user) = "parse";

let get = () : Js.Promise.t(array(Model.user)) =>
  Js.Promise.(
    Fetch.fetch(server)
    |> then_(Fetch.Response.text)
    |> then_(text => parse(text) |> resolve)
  );
