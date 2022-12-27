#!/bin/bash
PASS=0
FAIL=0
TESTS=17

echo -e "\n\e[92m===================================\e[0m\n"

for ((i=0;i<TESTS;i++)); do
	if "tests/test${i}" 2>&1 | diff -q "tests/test${i}.res" - >/dev/null; then
		read -r CASE < "tests/test${i}.c"
		CASE=$(echo ${CASE} | sed 's/\/\///g')
		echo -e "\e[92mPASS\e[0m: Test ${i} - ${CASE}"
		let "PASS+=1"
	else
		read -r CASE < "tests/test${i}.c"
		CASE=$(echo ${CASE} | sed 's/\/\///g')
		echo -e "\e[91mFAIL\e[0m: Test ${i} - ${CASE}"
		let "FAIL+=1"
	fi
done

echo

echo -e "\e[92m===================================\e[0m"
echo -e "\e[92mList.h Test Results\e[0m"
echo -e "\e[92m===================================\e[0m"
echo -e "\e[1m# TOTAL: ${TESTS}\e[0m"
if [[ ${PASS} -ne 0 ]]; then
	echo -e "\e[92m# PASS: ${PASS}\e[0m"
else
	echo -e "# PASS: ${PASS}"
fi
if [[ ${FAIL} -ne 0 ]]; then
	echo -e "\e[91m# FAIL: ${FAIL}\e[0m"
else
	echo -e "# FAIL: ${FAIL}"
fi
echo -e "\e[92m===================================\e[0m"
