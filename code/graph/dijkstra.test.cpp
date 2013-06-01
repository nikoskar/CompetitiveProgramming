#include <fstream>
map<int, ii> res;

void test_1() {
    int n = 2;
    vvii adj_list(n);

    res = dijkstra_path(0, adj_list);
    assert_true(res.find(1) == res.end());
    assert_true(res.find(0) != res.end());
    assert_equal(0, res[0].first);
    assert_equal(0, res[0].second);

    res = dijkstra_path(1, adj_list);
    assert_true(res.find(0) == res.end());
    assert_true(res.find(1) != res.end());
    assert_equal(0, res[1].first);
    assert_equal(1, res[1].second);
}

void test_2() {
    int n = 2;
    vvii adj_list(n);
    adj_list[0].push_back(ii(42, 1));

    res = dijkstra_path(0, adj_list);
    assert_true(res.find(1) != res.end());
    assert_true(res.find(0) != res.end());
    assert_equal(42, res[1].first);
    assert_equal(0, res[1].second);
    assert_equal(0, res[0].first);
    assert_equal(0, res[0].second);

    res = dijkstra_path(1, adj_list);
    assert_true(res.find(0) == res.end());
    assert_true(res.find(1) != res.end());
    assert_equal(0, res[1].first);
    assert_equal(1, res[1].second);
}

void test_3() {
    int n = 2;
    vvii adj_list(n);
    adj_list[0].push_back(ii(42, 1));
    adj_list[1].push_back(ii(42, 0));

    res = dijkstra_path(0, adj_list);
    assert_true(res.find(1) != res.end());
    assert_true(res.find(0) != res.end());
    assert_equal(42, res[1].first);
    assert_equal(0, res[1].second);
    assert_equal(0, res[0].first);
    assert_equal(0, res[0].second);

    res = dijkstra_path(1, adj_list);
    assert_true(res.find(1) != res.end());
    assert_true(res.find(0) != res.end());
    assert_equal(0, res[1].first);
    assert_equal(1, res[1].second);
    assert_equal(42, res[0].first);
    assert_equal(1, res[0].second);
}

void test_4() {
    int n = 4;
    vvii adj_list(n);
    adj_list[0].push_back(ii(5, 1));
    adj_list[1].push_back(ii(8, 2));
    adj_list[1].push_back(ii(30, 3));
    adj_list[2].push_back(ii(7, 3));

    res = dijkstra_path(0, adj_list);
    assert_true(res.find(1) != res.end());
    assert_equal(5, res[1].first);
    assert_equal(0, res[1].second);
    assert_true(res.find(2) != res.end());
    assert_equal(13, res[2].first);
    assert_equal(1, res[2].second);
    assert_true(res.find(3) != res.end());
    assert_equal(20, res[3].first);
    assert_equal(2, res[3].second);

    res = dijkstra_path(3, adj_list);
    assert_true(res.find(0) == res.end());
    assert_true(res.find(1) == res.end());
    assert_true(res.find(2) == res.end());

    res = dijkstra_path(1, adj_list);
    assert_true(res.find(3) != res.end());
    assert_equal(15, res[3].first);
}

void test_5() {
    int n = 4;
    vvii adj_list(4);
    adj_list[0].push_back(ii(4, 1));
    adj_list[0].push_back(ii(5, 2));
    adj_list[1].push_back(ii(2, 3));
    adj_list[2].push_back(ii(-5, 1));

    res = dijkstra_path(0, adj_list);
    assert_true(res.find(0) != res.end());
    assert_equal(0, res[0].first);
    assert_true(res.find(2) != res.end());
    assert_equal(5, res[2].first);
    assert_equal(0, res[2].second);
    assert_true(res.find(1) != res.end());
    assert_equal(0, res[1].first);
    assert_equal(2, res[1].second);
    assert_true(res.find(3) != res.end());
    assert_equal(2, res[3].first);
    assert_equal(1, res[3].second);
}

void test_6() {
    ifstream ifs("dijkstra_fast.test.in");
    int ts;
    ifs >> ts;
    for (int t = 0; t < ts; t++) {
        int n, m;
        ifs >> n >> m;
        vector<vector<ii> > adj(n);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            ifs >> a >> b >> c;
            adj[a].push_back(ii(c, b));
        }

        for (int i = 0; i < n; i++) {
            map<int, ii> res = dijkstra_path(i, adj);
            for (int j = 0; j < n; j++) {
                int correct;
                ifs >> correct;

                if (correct == -1) {
                    assert_equal(INF, res.find(j) == res.end() ? INF : res[j].first);
                } else {
                    assert_equal(correct, res.find(j) == res.end() ? INF : res[j].first);
                }
            }
        }
    }
}

void test() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
}
