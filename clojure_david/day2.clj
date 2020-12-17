
(defn validate1 [line]
    (let
        [
            [requirementText password]  (clojure.string/split line #": ")
            freqs                       (frequencies password)
            [amount character]          (clojure.string/split requirementText #" ")
            [min max]                   (clojure.string/split amount #"-")              
        ]
        (and
            (get freqs (nth character 0))
            freqs(<= (Integer/parseInt min) (get freqs (nth character 0)) (Integer/parseInt max))
        )
    )
)

; Part 1
(defn day2part1 []
    (println
        (frequencies
            (for [line (clojure.string/split-lines (slurp "data/day2.txt"))]
                (validate1 line)
            )
        )
    )
)

(day2part1 ) ; true is correct answer

; Part 2
(defn validate2 [line]
    (let
        [
            [requirementText password]  (clojure.string/split line #": ")
            [amount character]          (clojure.string/split requirementText #" ")
            [min max]                   (clojure.string/split amount #"-")              
        ]
        (and 
            (>= (count password) (Integer/parseInt max))
            (=
                (not (= (char (nth password (- (Integer/parseInt min) 1) )) (char (nth character 0) )) ) 
                (= (char (nth password (- (Integer/parseInt max) 1))) (char (nth character 0) ))
            )
        )
    )
)

(defn day2part2 []
    (println
        (frequencies
            (for [line (clojure.string/split-lines (slurp "data/day2.txt"))]
                (validate2 line)
            )
        )
    )
)

(day2part2 ) ; true is correct answer