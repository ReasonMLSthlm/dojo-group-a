let server = "https://immense-river-25513.herokuapp.com/locations"

let get = () => Js.Promise.(
  Fetch.fetch(server)
  |> then_(Fetch.Response.text)
  |> then_(text => print_endline(text) |> resolve)
  );
