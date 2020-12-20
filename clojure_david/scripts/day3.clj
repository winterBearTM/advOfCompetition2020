(defn check [lines position change]
    (let [
        horizontalChange    (nth change 0)
        verticalChange      (nth change 1)
        tree                (if (= (nth (nth lines 0) position) \#) 1 0 )
        previous            (if (> (count lines) 1)
                                (check
                                    (take-last (- (count lines) verticalChange) lines)
                                    (mod
                                        (+ position horizontalChange)
                                        (count (nth lines 0))
                                    )
                                    change
                                )
                                0
                            )
        ]
    (+ previous tree)
    )
)

(println
    (check  (clojure.string/split-lines (slurp "data/day3.txt"))
            0
            [3 1]
    )
)

(println
    (*
        (check  (clojure.string/split-lines (slurp "data/day3.txt"))
                0
                [1 1]
        )
        (check  (clojure.string/split-lines (slurp "data/day3.txt"))
                0
                [3 1]
        )
        (check  (clojure.string/split-lines (slurp "data/day3.txt"))
                0
                [5 1]
        )
        (check  (clojure.string/split-lines (slurp "data/day3.txt"))
                0
                [7 1]
        )
        (check  (clojure.string/split-lines (slurp "data/day3.txt"))
                0
                [1 2]
        )
    )
)