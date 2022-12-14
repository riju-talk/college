pop=[50,1450,1400,1700,1500,600,1200] #list for current population
def population_curr_and_max(pop):
    currpop=0
    list_of_tp=[]
    rate=2.5
    i=0
    while(rate>=0):
        rate1=rate
        for j in range(len(pop)):
            if(i==0):
                currpop+=pop[j]
            pop[j]+=round(pop[j]*rate1,2)
            rate1-=0.4
        list_of_tp.append(round(sum(pop),2))
        i+=1
        rate-=0.1
    print("The current population is:",currpop)
    return i
 
pop_max=population_curr_and_max(pop)
print("years untill maximum pop:",pop_max)
