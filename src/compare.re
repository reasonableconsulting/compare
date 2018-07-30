let concat = comparators => {
  let rec cmp = (comparators, firstValue, secondValue) =>
    switch (comparators) {
    | [] => compare(firstValue, secondValue)
    | [comparator, ...rest] =>
      let result = comparator(firstValue, secondValue);
      if (result == 0) {
        cmp(rest, firstValue, secondValue);
      } else {
        result;
      };
    };

  cmp(comparators);
};

let by = (comparator, firstValue, secondValue) =>
  compare(comparator(firstValue), comparator(secondValue));
