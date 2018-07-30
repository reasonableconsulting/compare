# compare

ReasonML helpers for generating cmp functions.

## Usage

```reason
module Comparator =
  Belt.Id.MakeComparable({
    type t = string;

    let cmp =
      Compare.concat([
        Compare.by(key => key),
        Compare.by(key => String.length(key)),
      ]);
  });

type t = Belt.Map.t(Comparator.t, int, Comparator.identity);

let ourMap = Belt.Map.fromArray(~id=(module Comparator), [|
  ("a", 1), ("b", 2), ("ab", 3)
|]);

Belt.Map.forEach(ourMap, Js.log2);
```

## License

MPL-2.0
