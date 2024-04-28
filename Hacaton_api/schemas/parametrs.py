from pydantic import BaseModel
from typing import Optional,List

class ParametrsBase(BaseModel):
    temperatura : float
    wet : float
    natural_gas : float
    gas : float
    dust1 : float
    dust2 : float
    dust3 : float
    lux : float



class ParametrsCreate(ParametrsBase):
    pass

class ParametrsUpdate(ParametrsBase):
    id:int
    status:bool
