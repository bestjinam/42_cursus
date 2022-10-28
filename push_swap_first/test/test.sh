#!/bin/bash

function	func()
{
	for i in {1..500}
	do
		./a.out "${i}"
	done
}

func
